// Problem 446: Arithmetic Slices II - Subsequence
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long,int>>dp(nums.size());
        int ans=0;
        for(int i=nums.size()-2;i>=0;--i){
            for(int j=i+1;j<nums.size();++j){
                long long diff=(long long)nums[i]-nums[j];
                int count=dp[j][diff];
                ans+=count;
                dp[i][diff]+=count+1;
            }
        }
        return ans;
    }
};