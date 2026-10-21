// Problem 1289: Minimum Falling Path Sum II
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<int>dp=grid[0];
        for(int i=1;i<grid.size();++i){
            vector<int>temp(dp.size());
            int num_temp=INT_MAX;
            for(int j=0;j<grid[i].size();++j){
                swap(dp[j],num_temp);
                temp[j]=*std::min_element(dp.begin(),dp.end())+grid[i][j];
                swap(dp[j],num_temp);
            }
            cout<<*std::min_element(dp.begin(),dp.end())<<endl;
            dp=temp;
        }
        return *std::min_element(dp.begin(),dp.end());
    }
};