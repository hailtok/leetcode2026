// Problem 132: Palindrome Partitioning II
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        vector<int>cuts(s.size());
        for(int i=0;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                if((i<2||dp[j+1][i+j-1])&&s[j]==s[i+j]){
                    dp[j][i+j]=true;
                }
            }
        }
        for(int i=0;i<s.size();++i){
            cuts[i]=i;
            if(dp[0][i]){
                cuts[i]=0;
            }
            else{
                for(int j=0;j<i;++j){
                    if(dp[j+1][i]){
                        cuts[i]=std::min(cuts[i],cuts[j]+1);
                    }
                }
            }
        }
        return cuts[cuts.size()-1];
    }
};