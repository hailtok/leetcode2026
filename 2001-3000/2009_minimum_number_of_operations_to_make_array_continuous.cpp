// Problem 2009: Minimum Number of Operations to Make Array Continuous
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<int> unique_nums=nums;
        unique_nums.erase(unique(unique_nums.begin(),unique_nums.end()),unique_nums.end());
        int max_keep = 0;
        for (int i=0;i<unique_nums.size();++i) {
            int count=upper_bound(unique_nums.begin(),unique_nums.end(),unique_nums[i]+nums.size()-1)-unique_nums.begin()-i;
            max_keep=max(max_keep,count);
        }
        return nums.size()-max_keep;
    }
};