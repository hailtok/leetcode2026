// Problem 3452: Sum of Good Numbers
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-good-numbers/

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();++i){
            int left=i-k<0?INT_MIN:nums[i-k],right=i+k>=nums.size()?INT_MIN:nums[i+k];
            if(left<nums[i]&&right<nums[i]){
                ans+=nums[i];
            }
        }
        return ans;
    }
};