// Problem 2428: Maximum Sum of an Hourglass
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-sum-of-an-hourglass/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int answer=0;
        for(int i=0;i+2<grid.size();++i){
            for(int j=0;j+2<grid[0].size();++j){
                int temp=0;
                for(int k=0;k<3;++k){
                    temp+=grid[i][j+k];
                }
                temp+=grid[i+1][j+1];
                for(int k=0;k<3;++k){
                    temp+=grid[i+2][j+k];
                }
                answer=std::max(answer,temp);
            }
        }
        return answer;
    }
};