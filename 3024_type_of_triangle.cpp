// Problem 3024: Type of Triangle
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/type-of-triangle/

class Solution {
public:
    string triangleType(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        if(nums[2]>=nums[0]+nums[1]){
           return "none"; 
        }
        if(nums[0]==nums[1]&&nums[1]==nums[2]){
            return "equilateral";
        }
        if(nums[0]==nums[1]||nums[1]==nums[2]||nums[0]==nums[2]){
            return "isosceles";
        }
        return "scalene";
    }
};