// Problem 1219: Path with Maximum Gold
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
public:
    int max_path=0;
    vector<std::pair<int,int>>direction={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid,int x,int y,int val){
        if(grid[x][y]==0){
            return;
        }
        max_path=std::max(max_path,val);
        int temp=grid[x][y];
        grid[x][y]=0;
        for(int i=0;i<4;++i){
            int new_x=x+direction[i].first,new_y=y+direction[i].second;
            if(new_x>=0&&new_x<grid.size()&&new_y>=0&&new_y<grid[0].size()&&grid[new_x][new_y]!=0){
                dfs(grid,new_x,new_y,val+grid[new_x][new_y]);
            }
        }
        grid[x][y]=temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                dfs(grid,i,j,grid[i][j]);
            }
        }
        return max_path;    
    }
};