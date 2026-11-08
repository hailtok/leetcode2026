// Problem 3195: Find the Minimum Area to Cover All Ones I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_height=INT_MAX,max_height=INT_MIN,min_width=INT_MAX,max_width=INT_MIN;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    min_height=std::min(min_height,i);
                    max_height=std::max(max_height,i);
                    min_width=std::min(min_width,j);
                    max_width=std::max(max_width,j);
                }
            }
        }
        return (max_width-min_width+1)*(max_height-min_height+1);
    }
};