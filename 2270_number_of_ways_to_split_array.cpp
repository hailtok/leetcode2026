// Problem 2270: Number of Ways to Split Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-ways-to-split-array/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long pre=0,total=std::accumulate(nums.begin(),nums.end(),0ll);
        int ans=0;
        for(int i=0;i<nums.size()-1;++i){
            pre+=nums[i];
            total-=nums[i];
            if(pre>=total){
                ++ans;
            }
        }
        return ans;
    }
};