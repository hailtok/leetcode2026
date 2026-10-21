// Problem 975: Odd Even Jump
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/odd-even-jump/

class Solution {
public:
    bool dfs(vector<int>&arr,vector<vector<int>>&next,vector<vector<int>>&dp,int index,int turn){
        if(index==arr.size()-1){
            return 1;
        }
        if(dp[index][turn]!=-1){
            return dp[index][turn];
        }
        int nxt=next[index][turn];
        if(nxt!=-1){
            dp[index][turn]=dfs(arr,next,dp,nxt,1-turn);
        }
        else{
            dp[index][turn]=0;
        }
        return dp[index][turn];
    }
    int oddEvenJumps(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(2,-1));
        vector<vector<int>>next(arr.size(),vector<int>(2,-1));
        map<int,int>map;
        for(int i=arr.size()-1;i>=0;--i){
            auto it_odd=map.lower_bound(arr[i]);
            if(it_odd!=map.end()){
                next[i][1]=it_odd->second;
            }
            auto it_even=map.upper_bound(arr[i]);
            if(it_even!=map.begin()){
                --it_even;
                next[i][0]=it_even->second;
            }
            map[arr[i]]=i;
        }
        int ans=0;
        for(int i=0;i<arr.size();++i){
            if(dfs(arr,next,dp,i,1)){
                ++ans;
            }
        }
        return ans;
    }
};