// Problem 1254: Number of Closed Islands
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    static constexpr int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(vector<vector<int>>& grid,int x,int y){
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()){
            return false;
        }
        if(grid[x][y]==1){
            return true;
        }
        grid[x][y]=1;
        bool land=true;
        for(int i=0;i<4;++i){
            if(!dfs(grid,x+dir[i][0],y+dir[i][1])){
                land=false;;
            }
        }
        return land;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==0&&dfs(grid,i,j)){
                    ++ans;
                }
            }
        }
        return ans;
    }
};