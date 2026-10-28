// Problem 1375: Number of Times Binary String Is Prefix-Aligned
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int right = 0, res = 0, n = light.size();
        for (int i = 0; i < n; ++i)
            res += (right = max(right, light[i])) == i + 1;
        return res;
    }
};