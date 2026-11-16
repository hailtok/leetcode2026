// Problem 2944: Minimum Number of Coins for Fruits
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-coins-for-fruits/

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n+1,0);
        dp[1]=prices[0];
        for(int i=1;i<=n;++i){
            dp[i]=dp[i-1]+prices[i-1];
            for(int j=1;j<i;++j){
                if(j+j<i){
                    continue;
                }
                dp[i]=std::min(dp[i],dp[j-1]+prices[j-1]);
            }
        }
        return dp[n];
    }
};