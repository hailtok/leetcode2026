// Problem 994: Rotting Oranges
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>&grid,vector<std::pair<int,int>>&rot,int round){
        if(rot.size()==0){
            ans=std::max(ans,round-1);
            return;
        }
        static constexpr int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        vector<std::pair<int,int>>new_rot;
        for(int i=0;i<rot.size();++i){
            for(int j=0;j<4;++j){
                int n_x=rot[i].first+dir[j][0],n_y=rot[i].second+dir[j][1];
                if(n_x>=0&&n_x<grid.size()&&n_y>=0&&n_y<grid[0].size()&&grid[n_x][n_y]==1){
                    grid[n_x][n_y]=2;
                    new_rot.push_back({n_x,n_y});
                }
            }
        }
        rot=new_rot;
        dfs(grid,rot,round+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<std::pair<int,int>>rot;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2){
                    rot.push_back({i,j});
                }
            }
        }
        dfs(grid,rot,0);
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};