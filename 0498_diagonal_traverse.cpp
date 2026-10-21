// Problem 498: Diagonal Traverse
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    void upper_right(vector<vector<int>>&mat,vector<int>&ans,int& i,int& j){
        while(i>=0&&j<mat[0].size()){
            ans.push_back(mat[i][j]);
            --i;
            ++j;
        }
        if(j==mat[0].size()){
            i+=2;
            j=mat[0].size()-1;
        }
        else{
            i=0;
        }
    }
    void down_left(vector<vector<int>>&mat,vector<int>&ans,int& i,int& j){
        while(i<mat.size()&&j>=0){
            ans.push_back(mat[i][j]);
            ++i;
            --j;
        }
        if(i==mat.size()){
            i=mat.size()-1;
            j+=2;
        }
        else{
            j=0;
        }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int i=0,j=0;
        while(true){
            upper_right(mat,ans,i,j);
            if(ans.size()>=mat.size()*mat[0].size()){
                break;
            }
            down_left(mat,ans,i,j);
            if(ans.size()>=mat.size()*mat[0].size()){
                break;
            }
        }
        return ans;
    }
};