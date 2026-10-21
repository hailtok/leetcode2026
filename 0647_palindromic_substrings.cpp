// Problem 647: Palindromic Substrings
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        int ans=s.size();
        for(int i=0;i<s.size();++i){
            dp[i][i]=true;
        }
        for(int i=1;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                if((i<2||dp[j+1][i+j-1])&&s[j]==s[i+j]){
                    ++ans;
                    dp[j][i+j]=true;
                }
            }
        }
        return ans;
    }
};