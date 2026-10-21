// Problem 628: Maximum Product of Three Numbers
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        std::sort(nums.begin(),nums.end());
        return std::max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
    }
};