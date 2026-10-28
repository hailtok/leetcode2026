// Problem 1752: Check if Array Is Sorted and Rotated
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int index=0;
        while(index+1<nums.size()&&nums[index+1]>=nums[index]){
            ++index;
        }
        ++index;
        for(int i=0;i<nums.size()-1;++i){
            if(nums[(index+i)%nums.size()]>nums[(index+i+1)%nums.size()]){
                return false;
            }
        }
        return true;
    }
};