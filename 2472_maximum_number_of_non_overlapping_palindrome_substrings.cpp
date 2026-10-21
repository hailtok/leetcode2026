// Problem 2472: Maximum Number of Non-overlapping Palindrome Substrings
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

class Solution {
public:
    int maxPalindromes(string s, int k) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                if((i<2||dp[j+1][i+j-1])&&s[j]==s[i+j]){
                    dp[j][i+j]=true;
                }
            }
        }
        int ans=0;
        for(int i=0;i<s.size();++i){
            if(i+k-1<s.size()&&dp[i][i+k-1]){
                ++ans;
                i+=k-1;
            }
            else if(i+k<s.size()&&dp[i][i+k]){
                ++ans;
                i+=k;
            }
        }
        return ans;
    }
};