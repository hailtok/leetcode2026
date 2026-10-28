// Problem 3619: Count Islands With Total Value Divisible by K
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/

class Solution {
public:
    static constexpr int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    long long dfs(vector<vector<int>>& grid,int x,int y){
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]==0){
            return 0;
        }
        long long total=grid[x][y];
        grid[x][y]=0;
        for(int i=0;i<4;++i){
            total+=dfs(grid,x+dir[i][0],y+dir[i][1]);
        }
        return total;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]!=0){
                    long long val=dfs(grid,i,j);
                    ans+=val%k==0?1:0;
                }
            }
        }
        return ans;
    }
};