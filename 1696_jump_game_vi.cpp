// Problem 1696: Jump Game VI
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/jump-game-vi/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp(nums.size());
        priority_queue<pair<int,int>>pq;
        for(int i=0,max=-10000;i+1<nums.size()&&i<k;++i){
            dp[i+1]=std::max(nums[0],max)+nums[i+1];
            max=std::max(max,dp[i+1]);
            pq.push({dp[i+1],i+1});
        }
        for(int i=k+1;i<dp.size();++i){
            dp[i]=pq.top().first+nums[i];
            while(!pq.empty()&&pq.top().second<=i-k){
                pq.pop();
            }
            pq.push({dp[i],i});
        }
        return dp[dp.size()-1];
    }
};