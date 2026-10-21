// Problem 231: Power of Two
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        n=n&(n-1);
        return n==0;
    }
};