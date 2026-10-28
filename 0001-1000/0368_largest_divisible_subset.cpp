// Problem 368: Largest Divisible Subset
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size(),vector<int>());
        for(int i=0;i<nums.size();++i){
            dp[i].push_back(nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i].size()<dp[j].size()+1){
                        dp[i]=dp[j];
                        dp[i].push_back(nums[i]);
                        if(dp[i].size()>ans.size()){
                            ans=dp[i];
                        }
                    }
                }
            }
        }
        if(ans.size()==0){
            return {nums[0]};
        }
        return ans;
    }
};