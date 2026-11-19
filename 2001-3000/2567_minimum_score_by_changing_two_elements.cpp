// Problem 2567: Minimum Score by Changing Two Elements
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-score-by-changing-two-elements/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size()-1;
        std::sort(nums.begin(),nums.end());
        return std::min(nums[n-1]-nums[1],std::min(nums[n-2]-nums[0],nums[n]-nums[2]));
    }
};