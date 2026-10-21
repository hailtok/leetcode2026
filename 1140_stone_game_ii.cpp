// Problem 1140: Stone Game II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        vector<int>suffix(piles.size(),0);
        for(int i=piles.size()-1,val=0;i>=0;--i){
            val+=piles[i];
            suffix[i]=val;
        }
        return solve(piles,dp,suffix,0,1);
    }
    int solve(vector<int>&piles,vector<vector<int>>&dp,vector<int>&suffix,int start,int M){
        if(start>=dp.size()){
            return 0;
        }
        if(start+2*M>=piles.size()){
            return suffix[start];
        }
        if(dp[start][M]!=-1){
            return dp[start][M];
        }
        for(int i=1;i<=2*M;++i){
            dp[start][M]=std::max(suffix[start]-solve(piles,dp,suffix,start+i,std::max(i,M)),dp[start][M]);
        }
        return dp[start][M];
    }
};