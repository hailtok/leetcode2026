// Problem 329: Longest Increasing Path in a Matrix
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>&dp,int x,int y,vector<vector<int>>&direction){
        for(int i=0;i<direction.size();++i){
            int new_x=x+direction[i][0],new_y=y+direction[i][1];
            if(new_x>=0&&new_x<dp.size()&&new_y>=0&&new_y<dp[0].size()&&matrix[x][y]<matrix[new_x][new_y]){
                if(dp[new_x][new_y]==0){
                    dp[x][y]=std::max(dp[x][y],dfs(matrix,dp,new_x,new_y,direction)+1);
                }
                else{
                    dp[x][y]=std::max(dp[x][y],dp[new_x][new_y]+1);
                }
            }
        }
        if(dp[x][y]==0){
            dp[x][y]=1;
        }
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=1;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                ans=std::max(ans,dfs(matrix,dp,i,j,direction));
            }
        }
        return ans;
    }
};