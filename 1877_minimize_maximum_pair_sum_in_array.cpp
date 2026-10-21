// Problem 1877: Minimize Maximum Pair Sum in Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int output=0;
        for(int i=0;i<nums.size();i++){
            output=max(output,nums[i]+nums[nums.size()-1-i]);
        }
        return output;
    }
};