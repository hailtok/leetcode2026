const fs = require('fs');
const path = require('path');

const SOURCE_FOLDERS = [
  'H:\\leetcode',
  'H:\\leetcode_2024_03_04',
  'H:\\leetcode2025'
];

const TARGET_DIR = 'H:\\leetcode2026';

function cleanTitle(filename) {
  let name = filename.replace(/\.txt$/, '');
  // 移除括號內的中文備註，例如 (垃圾)、(可優化)、(需複習) 等
  name = name.replace(/\([^)]*[\u4e00-\u9fa5]+[^)]*\)/g, '');
  return name.trim();
}

function normalizeTitle(str) {
  return str.toLowerCase().replace(/[^a-z0-9]/g, '');
}

const sleep = (ms) => new Promise(r => setTimeout(r, ms));

async function getLeetCodeQuestionInfo(title) {
  const query = `query problemsetQuestionList($filters: QuestionListFilterInput) {
    problemsetQuestionList: questionList(categorySlug: "", limit: 10, skip: 0, filters: $filters) {
      questions: data {
        questionFrontendId
        titleSlug
        title
        difficulty
      }
    }
  }`;

  try {
    const res = await fetch("https://leetcode.com/graphql", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        query,
        variables: { filters: { searchKeywords: title } }
      })
    });
    const data = await res.json();
    const questions = data?.data?.problemsetQuestionList?.questions || [];
    
    const targetNorm = normalizeTitle(title);
    // 優先完全比對（忽略大小寫與符號）
    for (const q of questions) {
      if (normalizeTitle(q.title) === targetNorm) {
        return q;
      }
    }
    // 次優：若第一個結果開頭符合
    if (questions.length > 0) {
      return questions[0];
    }
  } catch (err) {
    console.error(`  [!] 查詢 ${title} 失敗:`, err.message);
  }
  return null;
}

async function main() {
  console.log('=== 開始整理三份歷史資料夾 ===');
  
  // 1. 讀取 TARGET_DIR 現有的題目以做去重
  const existingFiles = fs.readdirSync(TARGET_DIR).filter(f => f.endsWith('.cpp'));
  const existingQuestions = new Set();
  
  for (const file of existingFiles) {
    const content = fs.readFileSync(path.join(TARGET_DIR, file), 'utf8');
    const firstLine = content.split('\n')[0].replace(/\r$/, '');
    const m = firstLine.match(/\/\/ Problem \d+: (.+)/);
    if (m) {
      existingQuestions.add(normalizeTitle(m[1]));
    }
    // 也把檔名去前綴放進去避免重複
    const slugFromName = file.replace(/^\d+_/, '').replace(/\.cpp$/, '');
    existingQuestions.add(normalizeTitle(slugFromName));
  }
  console.log(`[+] leetcode2026 現有 ${existingFiles.length} 題解答`);

  // 2. 收集來源檔案並去重
  const uniqueQuestionsToProcess = new Map(); // normalizedTitle -> { originalTitle, folder, file, code }
  let duplicateCount = 0;

  for (const folder of SOURCE_FOLDERS) {
    if (!fs.existsSync(folder)) continue;
    const files = fs.readdirSync(folder).filter(f => f.endsWith('.txt'));
    for (const file of files) {
      const title = cleanTitle(file);
      const norm = normalizeTitle(title);
      const filePath = path.join(folder, file);
      const code = fs.readFileSync(filePath, 'utf8').trim();

      if (uniqueQuestionsToProcess.has(norm)) {
        duplicateCount++;
        // 若後面的檔案更詳細或不同版本，可考慮覆蓋，這裡保留第一個或較長者
        const existing = uniqueQuestionsToProcess.get(norm);
        if (code.length > existing.code.length) {
          uniqueQuestionsToProcess.set(norm, { originalTitle: title, folder, file, code });
        }
      } else {
        uniqueQuestionsToProcess.set(norm, { originalTitle: title, folder, file, code });
      }
    }
  }

  console.log(`[+] 從 3 個來源資料夾共收集到 ${uniqueQuestionsToProcess.size} 題獨立題目 (跨資料夾重複跳過: ${duplicateCount})`);

  // 3. 處理每道題目，檢查是否已經在 leetcode2026 中
  let addedCount = 0;
  let skippedAlreadyIn2026 = 0;
  const itemsToAdd = [];

  for (const [norm, item] of uniqueQuestionsToProcess.entries()) {
    if (existingQuestions.has(norm)) {
      skippedAlreadyIn2026++;
      continue;
    }
    itemsToAdd.push(item);
  }

  console.log(`[+] 其中 ${skippedAlreadyIn2026} 題在 2026 中已存在 (已去重)，需要新增匯入 ${itemsToAdd.length} 題`);

  // 4. 逐題取得 LeetCode 題號與 slug 並轉存為 .cpp
  for (let i = 0; i < itemsToAdd.length; i++) {
    const item = itemsToAdd[i];
    process.stdout.write(`\r[${i + 1}/${itemsToAdd.length}] 正在解析: ${item.originalTitle}...`);
    
    const info = await getLeetCodeQuestionInfo(item.originalTitle);
    let frontendId = '0000';
    let titleSlug = item.originalTitle.toLowerCase().replace(/[^a-z0-9]+/g, '-').replace(/^-|-$/g, '');
    let officialTitle = item.originalTitle;
    let difficulty = 'Medium';

    if (info) {
      frontendId = info.questionFrontendId;
      titleSlug = info.titleSlug;
      officialTitle = info.title;
      difficulty = info.difficulty;
    }

    const paddedId = String(frontendId).padStart(4, '0');
    const filename = `${paddedId}_${titleSlug.replace(/-/g, '_')}.cpp`;
    const targetPath = path.join(TARGET_DIR, filename);

    const header = [
      `// Problem ${frontendId}: ${officialTitle}`,
      `// Difficulty: ${difficulty}`,
      `// Language: cpp`,
      `// URL: https://leetcode.com/problems/${titleSlug}/`,
      '',
      '',
    ].join('\n');

    fs.writeFileSync(targetPath, header + item.code, 'utf8');
    existingQuestions.add(normalizeTitle(officialTitle));
    existingQuestions.add(normalizeTitle(titleSlug));
    addedCount++;

    await sleep(250); // 溫和請求避免限流
  }

  console.log(`\n[✓] 成功將 ${addedCount} 題轉換並加入 H:\\leetcode2026`);

  // 5. 重新生成 README.md 完整索引
  console.log('[+] 正在重新生成 README.md ...');
  const allCppFiles = fs.readdirSync(TARGET_DIR).filter(f => f.endsWith('.cpp'));
  const entries = [];

  for (const file of allCppFiles) {
    const fullPath = path.join(TARGET_DIR, file);
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
  readme += `> 自動整合並生成於 ${new Date().toLocaleDateString('zh-TW')}\n\n`;
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

  fs.writeFileSync(path.join(TARGET_DIR, 'README.md'), readme, 'utf8');
  console.log(`[✓] README.md 生成完畢，共收錄 ${entries.length} 題解題紀錄！`);
}

main().catch(err => {
  console.error('[X] 執行失敗:', err);
  process.exit(1);
});

