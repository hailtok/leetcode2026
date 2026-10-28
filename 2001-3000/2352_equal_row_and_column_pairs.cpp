// Problem 2352: Equal Row and Column Pairs
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        for(int i=0;i<grid.size();i++){
            mp[grid[i]]++;
        }
        int output=0;
        for(int i=0;i<grid[0].size();i++){
            vector<int>temp;
            for(int j=0;j<grid.size();j++){
                temp.push_back(grid[j][i]);
            }
            output+=mp[temp];
        }
        return output;
    }
};