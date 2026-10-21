// Problem 485: Max Consecutive Ones
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,count=0;
        for(int i=0;i<nums.size();++i){
            count=nums[i]?++count:0;
            ans=std::max(ans,count);
        }
        return ans;
    }
};