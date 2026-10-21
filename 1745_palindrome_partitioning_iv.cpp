// Problem 1745: Palindrome Partitioning IV
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/palindrome-partitioning-iv/

class Solution {
public:
    bool checkPartitioning(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                if(s[j]==s[i+j]&&(i<2||dp[j+1][i+j-1])){
                    dp[j][i+j]=true;
                }
            }
        }
        int left=0;
        while(left<s.size()-2){
            if(dp[0][left]){
                for(int mid=left+1;mid<s.size()-1;++mid){
                    if(dp[left+1][mid]&&dp[mid+1][s.size()-1]){
                        return true;
                    }
                }
            }
            ++left;
        }
        return false;
    }
};