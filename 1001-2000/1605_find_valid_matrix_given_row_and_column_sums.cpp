// Problem 1605: Find Valid Matrix Given Row and Column Sums
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>output(rowSum.size(),vector<int> (colSum.size()));
        int col=0;
        for(int row=0;row<rowSum.size();row++){
            while(rowSum[row]!=0){
                if(rowSum[row]>colSum[col]){
                    rowSum[row]-=colSum[col];
                    output[row][col]+=colSum[col];
                    col++;
                }
                else{
                    output[row][col]+=rowSum[row];
                    colSum[col]-=rowSum[row];
                    rowSum[row]=0;
                }
            }
        }
        return output;
    }
};
