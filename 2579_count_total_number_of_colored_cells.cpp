// Problem 2579: Count Total Number of Colored Cells
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-total-number-of-colored-cells/

class Solution {
public:
    long long coloredCells(int n) {
        return (long long)(n-1)*(long long)(n-1)+(long long)n*(long long)n;
    }
};