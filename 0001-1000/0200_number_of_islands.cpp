// Problem 200: Number of Islands
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int ans=0;
    bool in_island(vector<vector<bool>>& grid,int x,int y){
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& check,int x,int y,vector<vector<int>>&direction){
        if(grid[x][y]=='0'){
            return;
        }
        for(int i=0;i<direction.size();++i){
            if(in_island(check,x+direction[i][0],y+direction[i][1])&&!check[x+direction[i][0]][y+direction[i][1]]&&grid[x+direction[i][0]][y+direction[i][1]]=='1'){
                check[x+direction[i][0]][y+direction[i][1]]=true;
                dfs(grid,check,x+direction[i][0],y+direction[i][1],direction);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>check=vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size()));
        vector<vector<int>>direction={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]=='1'&&!check[i][j]){
                    check[i][j]=true;
                    dfs(grid,check,i,j,direction);
                    ++ans;
                }
            }
        }
        return ans;
    }
};