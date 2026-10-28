// Problem 283: Move Zeroes
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[index]=nums[i];
                index++;
            }
        }
        for(int i=nums.size()-1;i>=index;i--){
            nums[i]=0;
        }
    }
};