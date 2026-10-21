// Problem 120: Triangle
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>dp(triangle.size(),triangle[0][0]);
        for(int i=1;i<triangle.size();i++){
            for(int j=triangle[i].size()-1;j>=0;j--){
                if(j==0){
                    dp[0]+=triangle[i][j];
                }
                else if(j==triangle[i].size()-1){
                    dp[j]=triangle[i][j]+dp[j-1];
                }
                else{
                    dp[j]=triangle[i][j]+min(dp[j-1],dp[j]);
                }
            }
        }
        int min=INT_MAX;
        for(int i=0;i<dp.size();i++){
            if(dp[i]<min){
                min=dp[i];
            }
        }
        return min;
    }
};