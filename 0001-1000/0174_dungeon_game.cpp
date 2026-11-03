// Problem 174: Dungeon Game
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int dfs(vector<vector<int>>&dungeon,int i,int j,vector<vector<int>>&dp){
        if(i==dungeon.size()||j==dungeon[0].size()){
            return 1e9;
        }
        
        if(i==dungeon.size()-1&&j==dungeon[0].size()-1){
            return std::max(1,1-dungeon[i][j]);
        }
        if(dp[i][j]!=1e9){
            return dp[i][j];
        }
        return dp[i][j]=std::max(std::min(dfs(dungeon,i+1,j,dp),dfs(dungeon,i,j+1,dp))-dungeon[i][j],1);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>>dp(dungeon.size(),vector<int>(dungeon[0].size(),1e9));
        return dfs(dungeon,0,0,dp);
    }
};