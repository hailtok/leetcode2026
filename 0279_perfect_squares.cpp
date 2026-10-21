// Problem 279: Perfect Squares
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        vector<unsigned>dp(n+1);

        for(int k=1;k<=n;k++){
            dp[k]=k;
            for(int i=1;i*i<=k;i++){
                dp[k]=min(1+dp[k-i*i],dp[k]);
            } 
        }
        return dp[n];
    }
};