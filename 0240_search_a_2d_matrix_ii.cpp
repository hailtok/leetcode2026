// Problem 240: Search a 2D Matrix II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j=matrix[0].size()-1,i=0;
        while(j>=0&&i<matrix.size()){
            if(matrix[i][j]>target){
                j--;
            }
            else if(matrix[i][j]<target){
                i++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};