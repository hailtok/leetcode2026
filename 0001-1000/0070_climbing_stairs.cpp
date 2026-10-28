// Problem 70: Climbing Stairs
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1){
            return 1;
        }
        int pre=1,cur=1;
        for(int i=2;i<=n;++i){
            int temp=cur;
            cur=pre+cur;
            pre=temp;
        }
        return cur;
    }
};