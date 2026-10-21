// Problem 1072: Flip Columns For Maximum Number of Equal Rows
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>umap;
        for(int i=0;i<matrix.size();++i){
            string sum="";
            for(int j=0;j<matrix[i].size();++j){
                if(matrix[i][0]==matrix[i][j]){
                    sum+='1';
                }
                else{
                    sum+='0';
                }
            }
            umap[sum]++;
        }
        int answer=0;
        for(auto it:umap){
            answer=max(answer,it.second);
        }
        return answer;
    }
};