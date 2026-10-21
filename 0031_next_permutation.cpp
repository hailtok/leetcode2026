// Problem 31: Next Permutation
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()>=2){
            int i=nums.size()-1;
            while(i>0){
                if(nums[i]>nums[i-1]){
                    int j=nums.size()-1;
                    while(nums[i-1]>=nums[j]){
                        j--;
                    }
                    swap(nums[i-1],nums[j]);
                    reverse(nums.begin()+i,nums.end());
                    break;
                }
                i--;
            }
        if(i==0){
            reverse(nums.begin(),nums.end());
            }
        }
    }
};