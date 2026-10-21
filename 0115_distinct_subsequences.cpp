// Problem 115: Distinct Subsequences
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // 使用 unsigned long long 防止中間運算溢位
        vector<unsigned long long> dp(m + 1, 0);
        
        // Base case: t 為空字串時，s 有一種方式匹配
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            // 注意：為了使用一維陣列，j 必須從後往前遍歷
            // 這樣 dp[j-1] 才會是上一個 i (也就是 dp[i-1][j-1]) 的值
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // 如果不相等，dp[j] 保持不變，等同於 dp[i][j] = dp[i-1][j]
            }
        }

        return (int)dp[m];
    }
};