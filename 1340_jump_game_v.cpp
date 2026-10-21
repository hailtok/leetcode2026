// Problem 1340: Jump Game V
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/jump-game-v/

class Solution {
public:
    int dfs(vector<int>&arr,int index,int&d,vector<int>&dp){
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=index-1;i>=0&&i>=index-d;--i){
            if(arr[index]>arr[i]){
                dp[index]=std::max(dp[index],dfs(arr,i,d,dp)+1);
            }
            else{
                break;
            }
        }
        for(int i=index+1;i<arr.size()&&i<=index+d;++i){
            if(arr[index]>arr[i]){
                dp[index]=std::max(dp[index],dfs(arr,i,d,dp)+1);
            }
            else{
                break;
            }
        }
        if(dp[index]==-1){
            dp[index]=0;
        }
        return dp[index];
    }
    int maxJumps(vector<int>& arr, int d) {
        vector<int>dp(arr.size(),-1);
        int ans=0;
        for(int i=0;i<arr.size();++i){
            if(dp[i]==-1){
                ans=std::max(dfs(arr,i,d,dp)+1,ans);
            }
            else{
                ans=std::max(ans,dp[i]);
            }
            //cout<<dp[i]<<endl;
        }
        return ans;
    }
};