// Problem 152: Maximum Product Subarray
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sum=INT_MIN,temp=1;
        for(int i=0;i<nums.size();++i){
            temp*=nums[i];
            sum=std::max(sum,temp);
            if(nums[i]==0){
                temp=1;
            }
        }
        temp=1;
        for(int i=nums.size()-1;i>=0;--i){
            temp*=nums[i];
            sum=std::max(sum,temp);
            if(nums[i]==0){
                temp=1;
            }
        }
        return sum;
    }
};