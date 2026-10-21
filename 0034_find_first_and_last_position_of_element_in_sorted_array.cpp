// Problem 34: Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int ans1=-1,ans2=-1;
    void r_binary_search(vector<int>&nums,int left,int right,int&target){
        if(left>right){
            return;
        }
        int pivot=left+(right-left)/2;
        if(nums[pivot]==target&&(pivot==nums.size()-1||nums[pivot+1]!=target)){
            ans2=pivot;
        }
        else if(nums[pivot]>target){
            r_binary_search(nums,left,pivot-1,target);
        }
        else{
            r_binary_search(nums,pivot+1,right,target);
        }
    }
    void l_binary_search(vector<int>&nums,int left,int right,int&target){
        if(left>right){
            return;
        }
        int pivot=left+(right-left)/2;
        if(nums[pivot]==target&&(pivot==0||nums[pivot-1]!=target)){
            ans1=pivot;
            r_binary_search(nums,pivot,nums.size()-1,target);
        }
        else if(nums[pivot]<target){
            l_binary_search(nums,pivot+1,right,target);
        }
        else{
            l_binary_search(nums,left,pivot-1,target);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        l_binary_search(nums,0,nums.size()-1,target);
        return {ans1,ans2};
    }
};