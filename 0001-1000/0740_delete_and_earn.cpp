// Problem 740: Delete and Earn
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>values(10001);
        for(int i=0;i<nums.size();i++){
            values[nums[i]]++;
        }
        int take=0,skip=0;
        for(int i=0;i<10001;i++){
            int take1=skip+values[i]*i;
            int skip1=max(take,skip);
            take=take1;
            skip=skip1;
        }
        return max(take,skip);
    }
};