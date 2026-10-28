// Problem 153: Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int gap=1,last=nums[0];
        while(gap<nums.size()){
            gap=gap<<1;
        }
        gap/=2;
        int pos=gap;
        while(gap!=0){    
            if(nums[pos]>nums[(pos+1)%nums.size()]){
                break;
            }
            if(nums[pos]>last){
                last=nums[pos];
                pos+=gap;
            }
            else{
                last=nums[pos];
                pos-=gap;
                if(pos<0){
                    pos+=nums.size();
                }
            }
            gap/=2;
            pos%=nums.size();
        }
        return nums[(pos+1)%nums.size()];
    }
};