// Problem 494: Target Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/target-sum/

class Solution {
public:
    int goal,size;
    vector<int>arrays;
    int recursion(int value,int index,vector<unordered_map<int,int>>& dp){
        if(index==size){
            return value==goal;
        }
        else{
            auto it=dp[index].find(value);
            if(it!=dp[index].end()){
                return it->second;
            }
            return dp[index][value]=recursion(value+arrays[index],index+1,dp)+recursion(value-arrays[index],index+1,dp);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size());
        goal=target;
        size=nums.size();
        for(int i=0;i<nums.size();i++){
            arrays.push_back(nums[i]);
        }
        return recursion(0,0,dp);
    }
};