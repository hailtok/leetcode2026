// Problem 3840: House Robber V
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/house-robber-v/

class Solution {
public:
    long long rob(vector<int>&nums){
        vector<long long>dp={0,nums[0]};
        for(int i=2;i<=nums.size();++i){
            dp.push_back(std::max(dp[i-2]+nums[i-1],dp[i-1]));
        }
        return dp[nums.size()];
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int color=colors[0],left=0;
        long long ans=0;
        for(int i=1;i<nums.size();++i){
            if(colors[i]!=color){
                color=colors[i];
                vector<int>temp(nums.begin()+left,nums.begin()+i);
                ans+=rob(temp);
                left=i;
                continue;
            }
        }
        vector<int>temp(nums.begin()+left,nums.end());
        ans+=rob(temp);
        return ans;
    }
};