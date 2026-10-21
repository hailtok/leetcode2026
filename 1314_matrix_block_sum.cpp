// Problem 1314: Matrix Block Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>output(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int temp=0;
                for(int g=i-k;g<=i+k;g++){
                    for(int h=j-k;h<=j+k;h++){
                        if(g>=0&&g<mat.size()&&h>=0&&h<mat[0].size()){
                            temp+=mat[g][h];
                        }
                    }
                }
                output[i][j]=temp;
            }
        }
        return output;
    }
};