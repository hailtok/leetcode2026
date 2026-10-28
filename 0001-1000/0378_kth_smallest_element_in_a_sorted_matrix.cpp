// Problem 378: Kth Smallest Element in a Sorted Matrix
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>index(matrix.size());
        while(k>1){
            k--;
            int temp_index=0,min=INT_MAX;
            for(int i=0;i<matrix.size();i++){
                if(index[i]==matrix.size()){
                    continue;
                }
                if(matrix[i][index[i]]<min){
                    min=matrix[i][index[i]];
                    temp_index=i;
                }
            }
            index[temp_index]++;
        }
        int output=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            if(index[i]<matrix.size()){
                output=min(matrix[i][index[i]],output);
            }    
        }
        return output;
    }
};