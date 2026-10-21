// Problem 5: Longest Palindromic Substring
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        string ans="";
        for(int i=0;i<s.size();++i){
            dp[i][i]=true;
        }
        for(int i=0;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                if((j+1>i+j-1||dp[j+1][i+j-1])&&s[j]==s[i+j]){
                    dp[j][i+j]=true;
                    if(i+1>ans.size()){
                        ans=s.substr(j,i+1);
                    }
                }
            }
        }
        return ans;
    }
};