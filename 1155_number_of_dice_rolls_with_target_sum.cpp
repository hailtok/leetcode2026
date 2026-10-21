// Problem 1155: Number of Dice Rolls With Target Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        map<int,unsigned>dp;
        for(int j=1;j<=k;j++){
            dp[j]++;
        }
         for(int i=1;i<n;i++){
             map<int,int>mp;
             for(int j=1;j<=k;j++){
                 for(auto it=dp.begin();it!=dp.end();it++){
                    mp[it->first+j]+=dp[it->first];
                    mp[it->first+j]%=1000000007;
                 }
             }
             dp.clear();
             for(auto it=mp.begin();it!=mp.end();it++){
                dp[it->first]=it->second;
             }
         }
         return dp[target]%1000000007;
    }
};