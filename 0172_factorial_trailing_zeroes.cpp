// Problem 172: Factorial Trailing Zeroes
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int five=0;
        for(int i=5;i<=n;i*=5){
            five+=(n/i);
        }
        return five;
    }
};