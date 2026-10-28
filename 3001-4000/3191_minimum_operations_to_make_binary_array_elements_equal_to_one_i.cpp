// Problem 3191: Minimum Operations to Make Binary Array Elements Equal to One I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i]==0){
                ++ans;
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
            }
        }
        if(nums[nums.size()-1]==0||nums[nums.size()-2]==0){
            return -1;
        }
        return ans;
    }
};