// Problem 3192: Minimum Operations to Make Binary Array Elements Equal to One II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool check=nums.back()==1?true:false;
        int ans=0;
        for(int i=nums.size()-2;i>=0;--i){
            if(nums[i]!=check){
                ++ans;
                check=!check;
            }
        }
        if(!check){
            ++ans;
        }
        return ans;
    }
};