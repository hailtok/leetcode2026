// Problem 413: Arithmetic Slices
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int output=0,cap=-1,length=-1;
        if(nums.size()>1){
            cap=nums[1]-nums[0];
        }
        else{
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            if(cap==nums[i]-nums[i-1]){
                length++;
            }
            else{
                cap=nums[i]-nums[i-1];
                if(length>0){
                    output+=(length*(length+1)/2);
                }
                length=0;
            }
        }
        if(length>0){
            output+=(length*(length+1)/2);
        }
        return output;
    }
};