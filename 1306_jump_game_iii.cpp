// Problem 1306: Jump Game III
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool recursion(int index,vector<int>&arr,vector<bool>&dp){
        if(index<0||index>=arr.size()||dp[index]){
            return false;
        }
        if(arr[index]==0){
            return true;
        }
        dp[index]=true;
        return recursion(index+arr[index],arr,dp)||recursion(index-arr[index],arr,dp);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>dp(arr.size(),false);
        return recursion(start,arr,dp);
    }
};