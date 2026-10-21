// Problem 213: House Robber II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int sum(vector<int>&nums,int left,int right){
        int pre=0,cur=0;
        for(int i=left;i<=right;++i){
            int temp=std::max(pre+nums[i],cur);
            pre=cur;
            cur=temp;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size()?nums[0]:0;
        }
        return std::max(sum(nums,0,nums.size()-2),sum(nums,1,nums.size()-1));
    }
};