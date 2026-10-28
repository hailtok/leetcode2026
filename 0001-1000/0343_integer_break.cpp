// Problem 343: Integer Break
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        if(n==3){
            return 2;
        }
        if(n==2){
            return 1;
        }
        int total=1,ren=n;
        while(ren>4){
            ren-=3;
            total*=3;
        }
        return total*ren;
    }
};