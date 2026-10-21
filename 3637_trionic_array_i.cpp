// Problem 3637: Trionic Array I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/trionic-array-i/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[1]<=nums[0]){
            return false;
        }
        bool first=false,second=false,third=false;
        int index=1;
        while(index<nums.size()){
            if(nums[index-1]>=nums[index]){
                first=true;
                break;
            }
            ++index;
        }
        while(index<nums.size()){
            if(nums[index-1]<=nums[index]){
                second=true;
                break;
            }
            ++index;
        }
        while(index<nums.size()){
            if(nums[index-1]>=nums[index]){
                break;
            }
            ++index;
            if(index==nums.size()){
                third=true;
                break;
            }
        }
        return first&&second&&third;
    }
};