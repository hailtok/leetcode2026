// Problem 2919: Minimum Increment Operations to Make Array Beautiful
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/

class Solution {
public:
    long long dfs(vector<long long>&dp,vector<int>&nums,int i,int &k){
        if(i>nums.size()-3){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long sub1=std::max(0,k-nums[i])+dfs(dp,nums,i+1,k);
        long long sub2=std::max(0,k-nums[i+1])+dfs(dp,nums,i+2,k);
        long long sub3=std::max(0,k-nums[i+2])+dfs(dp,nums,i+3,k);
        dp[i]=std::min(sub1,std::min(sub2,sub3));
        return dp[i];
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long>dp(nums.size(),-1);
        dfs(dp,nums,0,k); 
        return dp[0];       
    }
};