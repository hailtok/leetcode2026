// Problem 3727: Maximum Alternating Sum of Squares
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-alternating-sum-of-squares/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            nums[i]=std::abs(nums[i]);
        }
        std:sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size()/2;++i){
            ans-=(nums[i]*nums[i]);
        }
        for(int i=nums.size()/2;i<nums.size();++i){
            ans+=(nums[i]*nums[i]);
        }
        return ans;
    }
};