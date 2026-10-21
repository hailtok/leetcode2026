// Problem 29: Divide Two Integers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (divisor==0) return INT_MAX;
        long long output=exp(log(abs((long)dividend))-log(abs((long)divisor)));
        if((long)dividend*(long)divisor<0){
            output=-output;
        }
        if(output>INT_MAX){
            output=INT_MAX;
        }
        return output;
    }
};