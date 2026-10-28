// Problem 1020: Number of Enclaves
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(vector<vector<int>>&map,vector<vector<bool>>&dp,vector<pair<int,int>>&direction,int x,int y){
        cout<<x<<endl;
        cout<<y<<endl;
        if(x==map.size()||x<0||y==map[0].size()||y<0||!map[x][y]){
            return;
        }
        if(map[x][y]==1){
            dp[x][y]=true;
        }
        for(int i=0;i<direction.size();++i){
            map[x][y]=false;
            dfs(map,dp,direction,x+direction[i].first,y+direction[i].second);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]){
                    ++ans;
                }
            }
        }
        vector<pair<int,int>>direction={{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<bool>>map(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();++i){
            dfs(grid,map,direction,i,0);
            dfs(grid,map,direction,i,grid[0].size()-1);
        }
        for(int i=0;i<grid[0].size();++i){
            dfs(grid,map,direction,0,i);
            dfs(grid,map,direction,grid.size()-1,i);
        }
        for(int i=0;i<map.size();++i){
            for(int j=0;j<map[0].size();++j){
                if(map[i][j]){
                    --ans;
                }
            }
        }
        return ans;
    }
};