// Problem 48: Rotate Image
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size()/2;i++){
            for(int j=0;j<matrix[0].size()-i*2-1;j++){
                for(int k=0;k<3;k++){
                    switch(k){
                        case 0:
                            swap(matrix[i][i+j],matrix[matrix[0].size()-1-i-j][i]);
                            break;
                        case 1:
                            swap(matrix[matrix[0].size()-1-i-j][i],matrix[matrix[0].size()-1-i][matrix[0].size()-1-i-j]);
                            break;
                        case 2:
                            swap(matrix[matrix[0].size()-1-i][matrix[0].size()-1-i-j],matrix[i+j][matrix[0].size()-1-i]);
                            break; 
                    }
                }
            }
        }
    }
};