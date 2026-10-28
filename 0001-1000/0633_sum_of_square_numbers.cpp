// Problem 633: Sum of Square Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=2;i*i<=c;++i){
            if(c%i==0){
                int exponent=0;
                while(c%i==0){
                    exponent++;
                    c/=i;
                }
                if(i%4==3&&exponent%2!=0){
                    return false;
                }
            }
        }
        return c%4!=3;
    }
};