// Problem 221: Maximal Square
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1));
        int ans=0;
        for(int i=1;i<=matrix.size();++i){
            for(int j=1;j<=matrix[0].size();++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=std::min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    ans=std::max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};