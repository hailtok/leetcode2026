// Problem 312: Burst Balloons
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()));
        for(int i=2;i<nums.size();i++){
            for(int left=0;left<nums.size()-i;left++){
                int right=left+i;
                for(int k=left+1;k<right;k++){
                    dp[left][right]=max(dp[left][right],nums[left] * nums[k] * nums[right] + dp[left][k] + dp[k][right]);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};