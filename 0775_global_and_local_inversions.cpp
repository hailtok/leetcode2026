// Problem 775: Global and Local Inversions
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/global-and-local-inversions/

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int min=nums.back();
        for(int i=nums.size()-1;i>=2;--i){
            min=std::min(min,nums[i]);
            if(min<nums[i-2]){
                return false;
            }
        }
        return true;
    }
};