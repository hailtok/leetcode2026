---
name: leetcode-push
description: 自動掃描 H:\leetcode2026 內新寫的 LeetCode 題目，查詢官方題號與難度進行標準化命名（如 0001_two_sum.cpp）、補齊題目標頭註解、分類歸檔至千位區間資料夾（如 0001-1000/），並重新生成 README.md（展示前 300 號題）後自動推送到 GitHub。當使用者提到「推上去」、「把新寫的leetcode推上去」、「leetcode push」或類似請求時使用此技能。
---

# LeetCode 題解自動化推送 Skill (`leetcode-push`)

本技能負責將使用者在 `H:\leetcode2026` 中撰寫的 LeetCode C++ 解題代碼進行全自動標準化、歸檔、更新 README 與推送到 GitHub。

---

## 🚀 觸發時機

當使用者發出以下或類似指令時自動觸發：
- 「幫我推上去」
- 「把新寫的 leetcode 推上去」
- 「把最新寫的推上去」
- 「推上 github」

---

## ⚙️ 執行步驟

執行本技能時，直接執行維護好的自動化腳本：

```powershell
node H:\leetcode2026\scripts\push.cjs
```

### 腳本內部自動執行的完整流程：
1. **偵測新檔案：** 透過 `git status -u --porcelain` 自動捕捉所有新增的 `.cpp` 檔案。
2. **查詢 LeetCode GraphQL：** 自動以檔名查詢題目的官方 Title、Slug、Difficulty 與官方 URL。
3. **格式化與補齊 Header：** 
   - 檔名規範化為：`{0000}_{slug}.cpp`（例如 `0001_two_sum.cpp`）
   - 代碼開頭補齊標準註解檔頭：
     ```cpp
     // Problem 1: Two Sum
     // Difficulty: Easy
     // Language: cpp
     // URL: https://leetcode.com/problems/two-sum/
     ```
4. **千位區間歸檔：** 根據題號自動移入對應的千位資料夾（如 `0001-1000/`、`1001-2000/`、`2001-3000/`、`3001-4000/` 等）。
5. **重新生成 README.md：** 
   - 更新 Easy / Medium / Hard 與總題數統計。
   - 更新資料夾區間導覽表。
   - 題目表格維持展示前 300 號題目（`id <= 300`）。
6. **Git Commit & Push：**
   - 執行 `git add -A`
   - 執行 `git commit -m "feat: add X new solved problems (total Y problems)"`
   - 執行 `git push origin main`

---

## 📋 執行完畢後的回報格式

執行完後向使用者回報：
1. **本次新增題目清單**（題號、題目名稱、難度、歸檔路徑）
2. **更新後最新統計數據**（總題數、Easy/Medium/Hard 分布）
3. **GitHub 倉庫連結：** [https://github.com/hailtok/leetcode2026](https://github.com/hailtok/leetcode2026)
