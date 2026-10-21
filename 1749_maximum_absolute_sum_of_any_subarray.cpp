// Problem 1749: Maximum Absolute Sum of Any Subarray
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum=0,min_sum=0,cur_max=0,cur_min=0;
        for(auto &num:nums){
            cur_max=std::max(num,cur_max+num);
            max_sum=std::max(max_sum,cur_max);
            cur_min=std::min(num,cur_min+num);
            min_sum=std::min(min_sum,cur_min);
        }
        return std::max(max_sum,std::abs(min_sum));
    }
};