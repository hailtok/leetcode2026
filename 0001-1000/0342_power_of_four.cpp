// Problem 342: Power of Four
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0&&!(n&(n-1))&&(n&0x55555555);
    }
};