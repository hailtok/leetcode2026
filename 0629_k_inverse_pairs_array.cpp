// Problem 629: K Inverse Pairs Array
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int kInversePairs(int n, int k) {
        constexpr int mod =1e9+7;
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,0));
        for(int i=1;i<n+1;++i){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=k;++j){
                long long val=dp[i-1][j]-(j>=i?dp[i-1][j-i]:0);
                dp[i][j]=(dp[i][j-1]+val+mod)%mod;
            }  
        }
        if(k==0){
            return dp[n][0];
        }
        return (dp[n][k]-dp[n][k-1]+mod)%mod;
    }
};