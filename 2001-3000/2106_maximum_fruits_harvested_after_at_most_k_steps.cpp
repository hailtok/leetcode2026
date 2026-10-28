// Problem 2106: Maximum Fruits Harvested After at Most K Steps
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int ans = 0;

        // 擷取可達範圍內的點
        vector<int> pos, val;
        for (auto& f : fruits) {
            if (abs(f[0] - startPos) <= k)
                pos.push_back(f[0]), val.push_back(f[1]);
        }

        int m = pos.size();
        vector<int> prefix(m + 1, 0);
        for (int i = 0; i < m; ++i)
            prefix[i + 1] = prefix[i] + val[i];

        // 先往左，兩種策略
        for (int i = 0; i < m; ++i) {
            int left = pos[i];
            if (left > startPos) break;
            int dist = startPos - left;

            // 方案1：左→右（來回）
            if (2 * dist <= k) {
                int max_right = startPos + (k - 2 * dist);
                int j = upper_bound(pos.begin(), pos.end(), max_right) - pos.begin();
                ans = max(ans, prefix[j] - prefix[i]);
            }

            // 方案2：左單向（不折返）
            if (dist <= k) {
                int j = upper_bound(pos.begin(), pos.end(), startPos) - pos.begin();
                ans = max(ans, prefix[j] - prefix[i]);
            }
        }

        // 先往右，兩種策略
        for (int j = m - 1; j >= 0; --j) {
            int right = pos[j];
            if (right < startPos) break;
            int dist = right - startPos;

            // 方案1：右→左（來回）
            if (2 * dist <= k) {
                int min_left = startPos - (k - 2 * dist);
                int i = lower_bound(pos.begin(), pos.end(), min_left) - pos.begin();
                ans = max(ans, prefix[j + 1] - prefix[i]);
            }

            // 方案2：右單向（不折返）
            if (dist <= k) {
                int i = lower_bound(pos.begin(), pos.end(), startPos) - pos.begin();
                ans = max(ans, prefix[j + 1] - prefix[i]);
            }
        }

        return ans;
    }
};
