// Problem 131: Palindrome Partitioning
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    void dfs(string& s,vector<vector<string>>&ans,vector<vector<bool>>&dp,vector<int>&path,int start){
        if(start==dp.size()){
            vector<string>temp;
            for(int i=1;i<path.size();++i){
                temp.push_back(s.substr(path[i-1],path[i]-path[i-1]));
            }
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<dp.size();++i){
            if(dp[start][i]){
                path.push_back(i+1);
                dfs(s,ans,dp,path,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<dp.size();++i){
            for(int j=0;j<=i;++j){
                dp[i][j]=true;
            }
        }
        for(int j=0;j<s.size();++j){
            for(int i=0;i<s.size();++i){
                if(i+1<s.size()&&i+j<s.size()&&i+j-1>=0){
                    dp[i][i+j]=dp[i+1][i+j-1]&&s[i]==s[i+j]?true:false;
                }
            }
        }
        vector<vector<string>>ans;
        vector<int>temp{0};
        dfs(s,ans,dp,temp,0);
        return ans;
    }
};