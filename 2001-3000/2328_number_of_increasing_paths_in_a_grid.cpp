// Problem 2328: Number of Increasing Paths in a Grid
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution {
public:
    static constexpr int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},mod=1e9+7;
    int dfs(vector<vector<int>>&grid,int x,int y,int prev,vector<vector<int>>&dp){
        if(x<0||x==grid.size()||y<0||y==grid[0].size()||prev>=grid[x][y]){
            return 0;
        }
        if(dp[x][y]!=0){
            return dp[x][y];
        }
        int total=0;
        for(int i=0;i<4;++i){
            total=(total+dfs(grid,x+dir[i][0],y+dir[i][1],grid[x][y],dp))%mod;
        }
        dp[x][y]=(total+1)%mod;
        return dp[x][y];
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                ans=(ans+dfs(grid,i,j,0,dp))%mod;
            }
        }
        return ans;
    }
};