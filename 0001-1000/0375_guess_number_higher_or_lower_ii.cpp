// Problem 375: Guess Number Higher or Lower II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:
    int recursion(vector<vector<int>>&dp,int start,int end){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]>0){
            return dp[start][end];
        }
        int value=INT_MAX;
        for(int i=start;i<=end;++i){
            value=min(value,i+max(recursion(dp,start,i-1),recursion(dp,i+1,end)));
        }
        dp[start][end]=value;
        return value;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recursion(dp,1,n);
    }
};