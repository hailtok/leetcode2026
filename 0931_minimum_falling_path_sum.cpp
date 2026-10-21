// Problem 931: Minimum Falling Path Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int>dp=matrix[0];
        for(int i=1;i<matrix.size();++i){
            vector<int>temp(dp.size());
            for(int j=0;j<matrix[i].size();++j){
                int candidate1=j-1>=0?dp[j-1]:dp[0],candidate2=dp[j],candidate3=j+1<matrix[i].size()?dp[j+1]:dp[j];
                temp[j]=std::min(candidate1,std::min(candidate2,candidate3))+matrix[i][j];
            }
            dp=temp;
        }
        return *std::min_element(dp.begin(),dp.end());
    }
};