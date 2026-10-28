// Problem 807: Max Increase to Keep City Skyline
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>max1(grid.size());
        vector<int>max2(grid[0].size());
        int ans=0;
        for(int i=0;i<grid.size();++i){
            int max=0;
            for(int j=0;j<grid[i].size();++j){
                max=std::max(max,grid[i][j]);
            }
            max1[i]=max;
        }
        for(int i=0;i<grid[0].size();++i){
            int max=0;
            for(int j=0;j<grid.size();++j){
                max=std::max(max,grid[j][i]);
            }
            max2[i]=max;
        }
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                ans+=std::min(max1[i],max2[j])-grid[i][j];
            }
        }
        return ans;
    }
};