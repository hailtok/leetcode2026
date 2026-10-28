// Problem 416: Partition Equal Subset Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int max=0,total=0;
        for(int i=0;i<nums.size();++i){
            max=std::max(max,nums[i]);
            total+=nums[i];
        }
        if(total&1||max>total/2){
            return false;
        }
        vector<bool>dp(total/2+1,false);
        dp[0]=true;
        for(int i=0;i<nums.size();++i){
            for(int j=total/2;j>=nums[i];--j){
                if(dp[j-nums[i]]){
                    dp[j]=true;
                }
            }
        }
        return dp[total/2];
    }
};