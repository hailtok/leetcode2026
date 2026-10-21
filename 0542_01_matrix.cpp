// Problem 542: 01 Matrix
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/01-matrix/

class Solution {
public:
    int get_distance(int x,int y,vector<vector<int>>&matrix){
        if(x<0||x>=matrix.size()||y<0||y>=matrix[0].size()||matrix[x][y]==-1){
            return 100000;
        }
        if(matrix[x][y]==0||matrix[x][y]==1){
            return matrix[x][y];
        }
        int distance=matrix[x][y];
        matrix[x][y]=-1;
        distance=min(distance,get_distance(x+1,y,matrix)+1);
        distance=min(distance,get_distance(x-1,y,matrix)+1);
        distance=min(distance,get_distance(x,y+1,matrix)+1);
        distance=min(distance,get_distance(x,y-1,matrix)+1);
        matrix[x][y]=distance;
        return distance;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    mat[i][j]=100000;
                }
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                get_distance(i,j,mat);
            }
        }
        return mat;
    }
};