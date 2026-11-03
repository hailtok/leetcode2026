// Problem 2713: Maximum Strictly Increasing Cells in a Matrix
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[0].size();++j){
                mp[mat[i][j]].push_back({i,j});
            }
        }
        vector<int>rowMax(mat.size(),0);
        vector<int>colMax(mat[0].size(),0);
        int ans=0;
        for(auto&[val,cells]:mp) {
            vector<int>dp(cells.size());
            for (int k=0;k<cells.size();++k) {
                int x=cells[k].first;
                int y=cells[k].second;
                dp[k]=std::max(rowMax[x],colMax[y])+1;
                ans=std::max(ans,dp[k]);
            }
            for (int k=0;k<cells.size();++k) {
                int x=cells[k].first;
                int y=cells[k].second;
                rowMax[x]=std::max(rowMax[x], dp[k]);
                colMax[y]=std::max(colMax[y], dp[k]);
            }
        }
        return ans;
    }
};