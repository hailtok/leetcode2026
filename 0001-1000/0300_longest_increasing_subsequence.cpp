// Problem 300: Longest Increasing Subsequence
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();++i){
            int index=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            if(index>=dp.size()){
                dp.push_back(nums[i]);
            }
            else{
                dp[index]=nums[i];
            }
        }
        return dp.size();
    }
};