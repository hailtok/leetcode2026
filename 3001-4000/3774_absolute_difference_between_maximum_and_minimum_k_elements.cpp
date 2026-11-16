// Problem 3774: Absolute Difference Between Maximum and Minimum K Elements
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<k;++i){
            ans+=nums[nums.size()-i-1];
            ans-=nums[i];
        }
        return ans;
    }
};