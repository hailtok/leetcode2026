// Problem 64: Minimum Path Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
                for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};