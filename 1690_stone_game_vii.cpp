// Problem 1690: Stone Game VII
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/stone-game-vii/

class Solution {
public:
    int dfs(vector<int>&nums,vector<vector<int>>&dp,int left,int right,int sum){
        if(left==right){
            return 0;
        }
        if(dp[left][right]!=-1e9){
            return dp[left][right];
        }
        dp[left][right]=std::max(sum-nums[left]-dfs(nums,dp,left+1,right,sum-nums[left]),sum-nums[right]-dfs(nums,dp,left,right-1,sum-nums[right]));
        return dp[left][right];
    }
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1e9));
        int total=std::accumulate(stones.begin(),stones.end(),0);
        return dfs(stones,dp,0,stones.size()-1,total);
    }
};