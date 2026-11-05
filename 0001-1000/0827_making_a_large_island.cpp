// Problem 827: Making A Large Island
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/making-a-large-island/

class Solution {
public:
    static constexpr int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>&grid,int x,int y,int index){
       if(x<0||x==grid.size()||y<0||y==grid[0].size()||grid[x][y]!=1){
            return 0;
       }
       grid[x][y]=index;
       int area=1;
       for(int i=0;i<4;++i){
            area+=dfs(grid,x+dir[i][0],y+dir[i][1],index);
       }
       return area;
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int index=2,ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j,index);
                    mp[index]=area;
                    ans=std::max(area,ans);
                    ++index;
                }
            }
        }
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==0){
                    unordered_set<int>neighboringIslands;
                    for (int k=0;k<4;++k) {
                        int nx=i+dir[k][0];
                        int ny=j+dir[k][1];
                        if (nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[nx][ny]>1) {
                            neighboringIslands.insert(grid[nx][ny]);
                        }
                    }
                    int currentArea=1;
                    for(int id:neighboringIslands) {
                        currentArea+=mp[id];
                    }
                    ans=max(ans,currentArea);
                }
            }
        }
        return ans;
    }
};