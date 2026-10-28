// Problem 908: Smallest Range I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/smallest-range-i/

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max=nums[0],min=nums[0];
        for(int i=0;i<nums.size();++i){
            max=std::max(max,nums[i]);
            min=std::min(min,nums[i]);
        }
        return max-min>k*2?max-min-2*k:0;
    }
};