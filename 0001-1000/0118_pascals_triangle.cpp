// Problem 118: Pascal's Triangle
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer;
        answer.push_back({1});
        for(int i=1;i<numRows;++i){
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<answer[i-1].size();++j){
                temp.push_back(answer[i-1][j-1]+answer[i-1][j]);
            }
            temp.push_back(1);
            answer.push_back(temp);
        }
        return answer;
    }
};