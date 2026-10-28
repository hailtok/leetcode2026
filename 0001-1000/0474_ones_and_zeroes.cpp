// Problem 474: Ones and Zeroes
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();++i){
            int ones=0,zeros=0;
            for(int j=0;j<strs[i].size();++j){
                strs[i][j]=='0'?++zeros:++ones;
            }
            for(int j=m;j>=zeros;--j){
                for(int k=n;k>=ones;--k){
                    dp[j][k]=std::max(dp[j][k],dp[j-zeros][k-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};