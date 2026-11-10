// Problem 3693: Climbing Stairs II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/climbing-stairs-ii/

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long>dp(n+1,LLONG_MAX);
        dp[0]=0;
        for(int i=0;i<n;++i) {
            if(dp[i]==LLONG_MAX){
                continue;
            }
            for(int step=1;step<=3&&i+step<=n;++step) {
                long long cost=(long long)step*step+costs[i+step-1];
                dp[i+step]=min(dp[i+step],dp[i]+cost);
            }
        }
        return dp[n];
    }
};