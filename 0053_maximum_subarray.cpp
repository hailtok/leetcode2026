// Problem 53: Maximum Subarray
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MaxSumHere =nums[0],MaxSumFar=nums[0];
        for(int i=1;i<nums.size();i++){
            MaxSumHere =max(MaxSumHere +nums[i],nums[i]);
            MaxSumFar=max(MaxSumFar,MaxSumHere);
        }
        return MaxSumFar;
    }
};