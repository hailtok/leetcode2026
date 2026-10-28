// Problem 154: Find Minimum in Rotated Sorted Array II
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int binary_search(vector<int>&nums,int left,int right){
        while(left<right){
        int pivot=left+(right-left)/2;
            if(nums[pivot]==nums[right]){
                return std::min(binary_search(nums,left,pivot),binary_search(nums,pivot+1,right));
            }
            if(nums[pivot]>nums[right]){
                left=pivot+1;
            }
            else{
                right=pivot;
            }
       }
       return nums[left];
    }
    int findMin(vector<int>& nums) {
       return binary_search(nums,0,nums.size()-1);
    }
};