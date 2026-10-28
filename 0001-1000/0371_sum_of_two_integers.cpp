// Problem 371: Sum of Two Integers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
        unsigned carry=a&b;
        while(carry){
            a^=b;
            b=carry<<1;
            carry=a&b;
        }
        return a^b;
    }
};