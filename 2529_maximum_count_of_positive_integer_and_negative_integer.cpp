// Problem 2529: Maximum Count of Positive Integer and Negative Integer
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int first_one= lower_bound(nums.begin(),nums.end(),1)-nums.begin(),first_zero= lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        return std::max((int)nums.size()-first_one,first_zero);
    }
};