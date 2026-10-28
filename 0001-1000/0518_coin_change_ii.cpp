// Problem 518: Coin Change II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/coin-change-ii/

class Solution {
public:
    int output=0;
    void recursion(vector<int>coins,int amount){
        if(amoount==0){
            output++;
        }
        for(int i=0;i<coins.size()&&amount>=coins[i];i++){
            recursion(coins,amount-coins[i]);
        }
    }
    int change(int amount, vector<int>& coins) {
        recursion(coins,amount);
        return output;
    }
};

優化版

class Solution {
public:
    int output=0;
    vector<vector<int>>dp;
    int recursion(vector<int>coins,int amount,int index){
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int temp=0;
        for(int i=index;i>=0;i--){
            if(coins[i]>amount){
                continue;
            }
            else{
                temp+=recursion(coins,amount-coins[i],i);
            }
        }
        dp[index][amount]=max(dp[index][amount],temp);
        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<int>temp(amount+1,-1);
        temp[0]=1;
        for(int i=0;i<=coins.size();i++){
            dp.push_back(temp);
        }
        recursion(coins,amount,coins.size()-1);
        return dp[coins.size()-1][amount];
    }
};