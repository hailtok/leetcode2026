// Problem 935: Knight Dialer
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/knight-dialer/

class Solution {
public:
    static constexpr int mod=1e9+7;
    int knightDialer(int n) {
        vector<vector<int>>dp(10,vector<int>(n+1,0));
        vector<vector<int>>road{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        for(int i=0;i<10;++i){
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;++i){
            for(int j=0;j<10;++j){
                for(int k=0;k<road[j].size();++k){
                    dp[j][i]=(dp[j][i]+dp[road[j][k]][i-1])%mod;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=9;++i){
            ans=(ans+dp[i][n-1])%mod;
        }
        return ans;
    }
};