// Problem 1253: Reconstruct a 2-Row Binary Matrix
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        if(upper+lower!=std::accumulate(colsum.begin(),colsum.end(),0)){
            return vector<vector<int>>();
        }
        vector<vector<int>>answer(2,vector<int>(colsum.size()));
        for(int i=0;i<colsum.size();++i){
            if(colsum[i]==2){
                answer[0][i]=1;
                upper--;
            }
        }
        for(int i=0;i<colsum.size();++i){
            if(colsum[i]==1&&upper!=0){
                upper--;
                answer[0][i]=1;
            }
        }
        for(int i=0;i<colsum.size();++i){
            if(colsum[i]==2){
                answer[1][i]=1;
                lower--;
            }
        }
        for(int i=0;i<colsum.size();++i){
            if(colsum[i]==1&&lower!=0&&answer[0][i]!=1){
                lower--;
                answer[1][i]=1;
            }
        }
        if(upper!=0||lower!=0){
            return vector<vector<int>>();
        }
        return answer;
    }
};