// Problem 566: Reshape the Matrix
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int w=mat.size(),h=mat[0].size();
        if(w*h!=r*c){
            return mat;
        }
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<w*h;++i){
            ans[i/c][i%c]=mat[i/h][i%h];
        }
        return ans;
    }
};