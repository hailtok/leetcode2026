// Problem 396: Rotate Function
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rotate-function/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int output=0,sum=0;
        for(int i=0;i<nums.size();i++){
            output+=i*nums[i];
            sum+=nums[i];
        }
        int temp=output;
        for(int i=nums.size()-1;i>=0;i--){
            temp=temp+(sum-nums[i])-(nums[i]*(nums.size()-1));
            output=max(temp,output);
        }
        return output;
    }
};