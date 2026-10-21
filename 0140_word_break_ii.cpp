// Problem 140: Word Break II
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    vector<string>ans;
    string dfs(string &s,int index,vector<string>&wordDict,vector<string>&dp,string sentence){
        if(index==s.size()){
            ans.push_back(sentence.substr(1,sentence.size()-1));
            return "";
        }
        if(dp[index].size()!=0){
            return dp[index];
        }
        string str="";
        for(int i=0;i<wordDict.size();++i){
            cout<<s.substr(index,wordDict[i].size())<<endl;
            cout<<wordDict[i]<<endl;
            if(s.substr(index,wordDict[i].size())==wordDict[i]){
                str=dfs(s,index+wordDict[i].size(),wordDict,dp,sentence+' '+wordDict[i]);
            }
        }
        dp[index]=str;
        return str;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>dp(s.size(),"");
        dfs(s,0,wordDict,dp,"");
        return ans;
    }
};