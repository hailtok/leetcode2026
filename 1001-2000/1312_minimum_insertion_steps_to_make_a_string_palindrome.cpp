// Problem 1312: Minimum Insertion Steps to Make a String Palindrome
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=1;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                int t1=dp[j+1][i+j-1]+(s[j]!=s[i+j]?2:0),t2=dp[j+1][i+j]+1,t3=dp[j][i+j-1]+1;
                dp[j][i+j]=std::min({t1,t2,t3});
            }
        }
        return dp[0][s.size()-1];
    }
};