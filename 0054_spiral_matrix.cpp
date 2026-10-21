// Problem 54: Spiral Matrix
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>output;
        int top=0,bottom=matrix.size()-1,right=matrix[0].size()-1,left=0,direction=1;
        while(left<=right && top<=bottom){
            if(direction==1){
                for(int i=left;i<=right;i++){
                    output.push_back(matrix[top][i]);
                }
                direction++;
                top++;
            }
            else if(direction==2){
                for(int i=top;i<=bottom;i++){
                    output.push_back(matrix[i][right]);
                }
                right--;
                direction++;
            }
            else if(direction==3){
                for(int i=right;i>=left;i--){
                    output.push_back(matrix[bottom][i]);
                }
                bottom--;
                direction++;
            }
            else{
                for(int i=bottom;i>=top;i--){
                    output.push_back(matrix[i][left]);
                }
                left++;
                direction=1;
            }
        }
        return output;
    }
};