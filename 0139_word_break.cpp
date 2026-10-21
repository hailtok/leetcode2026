// Problem 139: Word Break
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/word-break/

class Solution {
public:
    bool dfs(vector<int>&dp,int index,vector<string>&words,string& s){
        if(index==dp.size()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=0;i<words.size();++i){
            string t=s.substr(index,words[i].size());
            if(index+words[i].size()<=s.size()&&s.substr(index,words[i].size())==words[i]){
                if(dfs(dp,index+words[i].size(),words,s)){
                    return dp[index]=1;
                }
            }
        }
        return dp[index]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return dfs(dp,0,wordDict,s);
    }
};