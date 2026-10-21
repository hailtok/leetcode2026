const fs = require('fs');
const path = require('path');

const CONFIG = {
  csrfToken: 'DD8ZBIynNJRNmNlSeunTuNPechdCt9E1',
  session: 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJfYXV0aF91c2VyX2lkIjoiMjY5MDY0OSIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6ImJhNjk2OTU1MTJkN2ZjMzNlZWQ0Nzg1ODUyYjQ4MzYzZjEyYTc0OWE0OTUwMGYzMmYyNWIxN2I3ZmM5NGNhYmMiLCJzZXNzaW9uX3V1aWQiOiJjZjIxZjBmZCIsImlkIjoyNjkwNjQ5LCJlbWFpbCI6ImhhbWJlcjEzNEBnbWFpbC5jb20iLCJ1c2VybmFtZSI6ImhhbWJlcjEzNCIsInVzZXJfc2x1ZyI6ImhhbWJlcjEzNCIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9oYW1iZXIxMzQvYXZhdGFyXzE1ODI3NDMxMjUucG5nIiwicmVmcmVzaGVkX2F0IjoxNzkyNTcyNzUzLCJpcCI6IjExNi4yNDEuMjEyLjExMyIsImlkZW50aXR5IjoiYzA2MDUyOGEwM2E2M2IxYmMxYjBkMWZkZjJhODhjZmUiLCJkZXZpY2Vfd2l0aF9pcCI6WyI1OGNjOGI2NzUwYjE4ZjBiZTRjZTkwYTgzYjg1MDc4NCIsIjExNi4yNDEuMjEyLjExMyJdLCJfc2Vzc2lvbl9leHBpcnkiOjEyMDk2MDB9.Fu6OV3TvNgw_PTFn-IksvT1wFfO2tf50E3LGC6PY8TI',
  outputDir: 'H:\\leetcode2026',
};

const HEADERS = {
  'Content-Type': 'application/json',
  'Cookie': `csrftoken=${CONFIG.csrfToken}; LEETCODE_SESSION=${CONFIG.session}`,
  'x-csrftoken': CONFIG.csrfToken,
  'Referer': 'https://leetcode.com',
  'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36',
};

const LANG_EXT = {
  cpp: '.cpp', 'c++': '.cpp', python3: '.py', python: '.py', java: '.java',
  javascript: '.js', typescript: '.ts', csharp: '.cs', golang: '.go', go: '.go',
  rust: '.rs', kotlin: '.kt', swift: '.swift', c: '.c', ruby: '.rb',
  scala: '.scala', php: '.php', dart: '.dart',
};

const sleep = (ms) => new Promise((r) => setTimeout(r, ms));

function normalizeTitle(str) {
  return str.toLowerCase().replace(/[^a-z0-9]/g, '');
}

// 建立題號對照表
async function buildProblemMap() {
  const map = new Map();
  let skip = 0;
  const limit = 100;
  let total = Infinity;

  while (skip < total) {
    let retries = 3;
    let res = null;
    while (retries > 0) {
      try {
        res = await fetch('https://leetcode.com/graphql', {
          method: 'POST',
          headers: HEADERS,
          body: JSON.stringify({
            query: `query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
              problemsetQuestionList: questionList(categorySlug: $categorySlug, limit: $limit, skip: $skip, filters: $filters) {
                total: totalNum
                questions: data {
                  questionFrontendId
                  titleSlug
                  title
                  difficulty
                }
              }
            }`,
            variables: { categorySlug: '', limit, skip, filters: {} },
          }),
        });
        if (res.ok) break;
      } catch (err) {}
      retries--;
      await sleep(2000);
    }

    if (!res || !res.ok) {
      console.error(`  ✗ GraphQL 請求失敗`);
      break;
    }

    const json = await res.json();
    const list = json.data?.problemsetQuestionList;
    if (!list) break;
    total = list.total;

    for (const q of list.questions) {
      map.set(q.titleSlug, {
        id: q.questionFrontendId,
        title: q.title,
        difficulty: q.difficulty,
      });
    }

    skip += limit;
    process.stdout.write(`\r  已載入 ${map.size} / ${total} 題...`);
    await sleep(600);
  }

  console.log(`\r  ✓ 題庫索引完成：共 ${map.size} 題          `);
  return map;
}

// 帶重試與退避的 API 呼叫
async function fetchSubmissionsPage(offset, limit) {
  const url = `https://leetcode.com/api/submissions/?offset=${offset}&limit=${limit}`;
  let retries = 5;
  let backoff = 2500;

  while (retries > 0) {
    try {
      const res = await fetch(url, { headers: HEADERS });
      if (res.status === 200) {
        return await res.json();
      } else if (res.status === 429 || res.status === 403) {
        console.log(`\n  [!] 遇到限流 (${res.status})，暫停 ${backoff / 1000} 秒後重試...`);
        await sleep(backoff);
        backoff *= 1.8;
      } else {
        console.error(`\n  [!] HTTP 錯誤 ${res.status}`);
        await sleep(backoff);
      }
    } catch (err) {
      console.error(`\n  [!] 網路錯誤: ${err.message}`);
      await sleep(backoff);
    }
    retries--;
  }
  return null;
}

// 抓取所有 AC 提交
async function fetchAllSubmissions() {
  const accepted = new Map(); // titleSlug -> sub
  let offset = 0;
  const limit = 20;
  let hasNext = true;
  let totalFetched = 0;

  while (hasNext) {
    const data = await fetchSubmissionsPage(offset, limit);
    if (!data || !data.submissions_dump) {
      console.error('\n  ✗ 無法取得提交紀錄，停止掃描');
      break;
    }

    for (const sub of data.submissions_dump) {
      if (sub.status_display === 'Accepted') {
        const existing = accepted.get(sub.title_slug);
        if (
          !existing ||
          (existing.lang !== 'cpp' && sub.lang === 'cpp') ||
          (existing.lang === sub.lang && sub.timestamp > existing.timestamp)
        ) {
          accepted.set(sub.title_slug, sub);
        }
      }
    }

    totalFetched += data.submissions_dump.length;
    hasNext = data.has_next;
    offset += limit;

    process.stdout.write(`\r  已掃描 ${totalFetched} 筆提交，找到 ${accepted.size} 題 AC...`);
    await sleep(1600); // 溫和間隔避免 403
  }

  console.log(`\r  ✓ 提交掃描完成：共找到 ${accepted.size} 題 AC 提交紀錄                  `);
  return accepted;
}

function saveAndRegenerateReadme(submissions, problemMap) {
  // 取得現有 2026 目錄檔案
  const existingFiles = fs.readdirSync(CONFIG.outputDir).filter(f => f.endsWith('.cpp'));
  const existingNorms = new Set();

  for (const f of existingFiles) {
    const content = fs.readFileSync(path.join(CONFIG.outputDir, f), 'utf8');
    const firstLine = content.split('\n')[0].replace(/\r$/, '');
    const m = firstLine.match(/\/\/ Problem \d+: (.+)/);
    if (m) existingNorms.add(normalizeTitle(m[1]));
    const slug = f.replace(/^\d+_/, '').replace(/\.cpp$/, '');
    existingNorms.add(normalizeTitle(slug));
  }

  let newlyAdded = 0;
  for (const [slug, sub] of submissions.entries()) {
    const info = problemMap.get(slug) || { id: '0000', title: sub.title || slug, difficulty: 'Medium' };
    const norm = normalizeTitle(info.title);
    const normSlug = normalizeTitle(slug);

    if (existingNorms.has(norm) || existingNorms.has(normSlug)) {
      continue; // 已存在不重複覆蓋
    }

    const paddedId = String(info.id).padStart(4, '0');
    const ext = LANG_EXT[sub.lang] || '.cpp';
    const filename = `${paddedId}_${slug.replace(/-/g, '_')}${ext}`;
    const filepath = path.join(CONFIG.outputDir, filename);

    const header = [
      `// Problem ${info.id}: ${info.title}`,
      `// Difficulty: ${info.difficulty}`,
      `// Language: ${sub.lang}`,
      `// URL: https://leetcode.com/problems/${slug}/`,
      '',
      '',
    ].join('\n');

    fs.writeFileSync(filepath, header + sub.code, 'utf8');
    existingNorms.add(norm);
    existingNorms.add(normSlug);
    newlyAdded++;
  }

  console.log(`  ✓ 成功從提交記錄補齊 ${newlyAdded} 題新程式碼至 H:\\leetcode2026`);

  // 重新生成 README.md
  const allCppFiles = fs.readdirSync(CONFIG.outputDir).filter(f => f.endsWith('.cpp'));
  const entries = [];

  for (const file of allCppFiles) {
    const fullPath = path.join(CONFIG.outputDir, file);
    const content = fs.readFileSync(fullPath, 'utf8');
    const lines = content.split('\n').map(l => l.replace(/\r$/, ''));
    
    let id = 0;
    let frontendId = '';
    let title = '';
    let difficulty = 'Medium';
    let url = '';

    for (let j = 0; j < Math.min(lines.length, 10); j++) {
      const l = lines[j];
      const mId = l.match(/\/\/ Problem (\d+): (.+)/);
      if (mId) {
        frontendId = mId[1];
        id = parseInt(frontendId, 10) || 0;
        title = mId[2];
      }
      const mDiff = l.match(/\/\/ Difficulty: (.+)/);
      if (mDiff) difficulty = mDiff[1].trim();
      const mUrl = l.match(/\/\/ URL: (.+)/);
      if (mUrl) url = mUrl[1].trim();
    }

    if (!title) {
      title = file.replace(/^\d+_/, '').replace(/\.cpp$/, '').replace(/_/g, ' ');
    }
    if (!url) {
      const slug = file.replace(/^\d+_/, '').replace(/\.cpp$/, '').replace(/_/g, '-');
      url = `https://leetcode.com/problems/${slug}/`;
    }

    entries.push({ id, frontendId: frontendId || String(id), title, difficulty, filename: file, url });
  }

  entries.sort((a, b) => a.id - b.id);

  const difficultyEmoji = { Easy: '🟢', Medium: '🟡', Hard: '🔴' };
  const easy = entries.filter((e) => e.difficulty === 'Easy').length;
  const medium = entries.filter((e) => e.difficulty === 'Medium').length;
  const hard = entries.filter((e) => e.difficulty === 'Hard').length;

  let readme = `# 🏆 LeetCode Solutions\n\n`;
  readme += `> **[hamber134](https://leetcode.com/u/hamber134/)** 的 LeetCode 解題紀錄\n`;
  readme += `> 自動整合並更新於 ${new Date().toLocaleDateString('zh-TW')}\n\n`;
  readme += `## 📊 統計\n\n`;
  readme += `| 難度 | 數量 |\n|------|------|\n`;
  readme += `| 🟢 Easy | ${easy} |\n`;
  readme += `| 🟡 Medium | ${medium} |\n`;
  readme += `| 🔴 Hard | ${hard} |\n`;
  readme += `| **總計** | **${entries.length}** |\n\n`;
  readme += `## 📝 題目列表\n\n`;
  readme += `| # | 題目 | 難度 | 語言 | 解答 |\n`;
  readme += `|--:|------|:----:|:----:|:----:|\n`;

  for (const e of entries) {
    const emoji = difficultyEmoji[e.difficulty] || '🟡';
    readme += `| ${e.frontendId} | [${e.title}](${e.url}) | ${emoji} ${e.difficulty} | cpp | [解答](./${e.filename}) |\n`;
  }

  fs.writeFileSync(path.join(CONFIG.outputDir, 'README.md'), readme, 'utf8');
  console.log(`  ✓ README.md 已更新，總共收錄 ${entries.length} 題解題檔案！`);
  return entries.length;
}

async function main() {
  console.log('=== 開始掃描並補齊所有 LeetCode 解答 ===');
  console.log('[1/3] 載入題目題號與詳細資訊...');
  const problemMap = await buildProblemMap();

  console.log('[2/3] 掃描所有歷史 AC 提交紀錄 (加入退避重試)...');
  const submissions = await fetchAllSubmissions();

  console.log('[3/3] 整理檔案與更新 README...');
  saveAndRegenerateReadme(submissions, problemMap);
}

main().catch(err => {
  console.error('執行失敗:', err);
  process.exit(1);
});
