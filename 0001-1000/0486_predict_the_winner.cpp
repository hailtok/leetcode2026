// Problem 486: Predict the Winner
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/predict-the-winner/

class Solution {
public:
    int recursion(int start,int end,bool check,vector<int>& nums,vector<vector<int>>&dp){

        if(start==end){
            return nums[start];
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(check){
            dp[start][end]=max(nums[start]+recursion(start+1,end,!check,nums,dp),recursion(start,end-1,!check,nums,dp)+nums[end]);
        }
        else{
            dp[start][end]=min(-nums[start]+recursion(start+1,end,!check,nums,dp),recursion(start,end-1,!check,nums,dp)-nums[end]);
        }
        return dp[start][end];
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        if(recursion(0,nums.size()-1,true,nums,dp)>=0){
            return true;
        }
        else{
            return false;
        }
    }
};