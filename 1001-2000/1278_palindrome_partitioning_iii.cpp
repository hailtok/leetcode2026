// Problem 1278: Palindrome Partitioning III
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/palindrome-partitioning-iii/

class Solution {
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>>cost(s.size(),vector<int>(s.size()));
        for(int len=2;len<=s.size();++len){
            for(int i=0;i+len<=s.size();++i){
                int j=i+len-1;
                cost[i][j]=(s[i]==s[j]?0:1)+(len>2?cost[i+1][j-1]:0);
            }
        }
        vector<vector<int>>dp(s.size()+1,vector<int>(k+1,s.size()));
        dp[0][0]=0;
        for(int i=1;i<=k;++i){
            for(int j=i;j<=s.size();++j){
                for(int k=i-1;k<j;++k){
                    dp[j][i]=std::min(dp[j][i],dp[k][i-1]+cost[k][j-1]);
                }
            }
        }
        return dp[s.size()][k];
    }
};