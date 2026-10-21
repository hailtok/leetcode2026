// Problem 2560: House Robber IV
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/house-robber-iv/

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left=0,right=1e9;
        while(left<right){
            int mid=left+(right-left)/2,take=0;
            for(int i=0;i<nums.size();++i){
                if(nums[i]<=mid){
                    ++take;
                    ++i;
                }
            }
            if(take>=k){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};