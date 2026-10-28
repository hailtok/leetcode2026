// Problem 334: Increasing Triplet Subsequence
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int max1=INT_MAX,max2=INT_MAX;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<=max1){
                max1=nums[i];
            }
            else if(nums[i]<=max2){
                max2=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};