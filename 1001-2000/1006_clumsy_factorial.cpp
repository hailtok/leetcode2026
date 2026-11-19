// Problem 1006: Clumsy Factorial
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/clumsy-factorial/

class Solution {
public:
    int clumsy(int n) {
        int left=0;
        if(n%4==1){
            left=1;
        }
        else if(n%4==2){
            left=2;
        }
        else if(n%4==3){
            left=6;
        }
        if(n<4){
            return left;
        }
        left=n*(n-1)/(n-2)+(n-3)-left;
        for(int i=n-4;i>=4;i-=4){
            left=left-i*(i-1)/(i-2)+(i-3);
        }
        return left;
    }
};