// Problem 35: Search Insert Position
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        if(target<nums[0]){
            return 0;
        }
        int left=0,right=nums.size()-1;
        while(left<right){
            int pivot=(left+right)/2;
            if(nums[pivot]<target){
                if(pivot==left){
                    return left+1;
                }
                left=pivot;
            }
            else if(nums[pivot]>target){
                if(pivot==right){
                    return right-1;
                }
                right=pivot;
            }
            else{
                return pivot;
            }
        }
        return left;
    }
};