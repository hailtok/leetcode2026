// Problem 540: Single Element in a Sorted Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size(),pivot=nums.size()/2;
        while(left!=pivot&&right!=pivot){
            if(pivot%2==0){
                if(nums[pivot]==nums[pivot-1]){
                    right=pivot;
                    pivot=(left+right)/2;
                }
                else if (nums[pivot]==nums[pivot+1]){
                    left=pivot;
                    pivot=(left+right)/2;
                }
                else{
                    break;
                }
            }
            else{
                if(nums[pivot]==nums[pivot+1]){
                    right=pivot;
                    pivot=(left+right)/2;
                }
                else if (nums[pivot]==nums[pivot-1]){
                    left=pivot;
                    pivot=(left+right)/2;
                }
                else{
                    break;
                }    
            }
        }
        return nums[pivot];
    }
};