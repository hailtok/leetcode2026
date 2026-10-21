// Problem 516: Longest Palindromic Subsequence
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size()));
        for(int i=0;i<s.size();++i){
            dp[i][i]=1;
        }
        for(int i=s.size()-1;i>=0;--i){
            for(int j=i+1;j<s.size();++j){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j]=std::max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};