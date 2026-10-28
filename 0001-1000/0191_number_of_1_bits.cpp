// Problem 191: Number of 1 Bits
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(int n) {
        int answer=0;
        while(n>0){
            answer+=(n&1);
            n=n>>1;
        }
        return answer;
    }
};