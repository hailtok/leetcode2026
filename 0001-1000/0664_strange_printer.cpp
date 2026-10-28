// Problem 664: Strange Printer
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/strange-printer/

class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),INT_MAX));
        for(int i=s.size()-1;i>=0;--i){
            dp[i][i]=1;
            for(int j=i+1;j<s.size();++j){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i][j-1];
                }
                else{
                    for(int k=i;k<j;++k){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][s.size()-1];
    }
};