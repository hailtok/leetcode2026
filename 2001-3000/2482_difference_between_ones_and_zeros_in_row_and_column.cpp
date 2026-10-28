// Problem 2482: Difference Between Ones and Zeros in Row and Column
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>>answer(grid.size(),vector<int>(grid[0].size()));
        vector<int>row_count(grid.size());
        vector<int>col_count(grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                row_count[i]+=grid[i][j];
            }
        }
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                col_count[i]+=grid[j][i];
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                answer[i][j]=row_count[i]*2+col_count[j]*2-grid.size()-grid[0].size();
            }
        }        
        return answer;
    }
};