// Problem 377: Combination Sum IV
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;++i){
            for(int j=0;j<nums.size();++j){
                if(i-nums[j]>=0){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};