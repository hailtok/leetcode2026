// Problem 3402: Minimum Operations to Make Columns Strictly Increasing
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid[0].size();++i){
            int cur=grid[0][i];
            for(int j=1;j<grid.size();++j){
                ans+=std::max(cur-grid[j][i]+1,0);
                grid[j][i]=std::max(grid[j][i],cur+1);
                cur=grid[j][i];
            }
        }
        return ans;
    }
};