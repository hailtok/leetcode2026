// Problem 1828: Queries on Number of Points Inside a Circle
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>output(queries.size());
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<points.size();j++){
                if((points[j][0]-queries[i][0])*(points[j][0]-queries[i][0])+(points[j][1]-queries[i][1])*(points[j][1]-queries[i][1])<=queries[i][2]*queries[i][2]){
                    output[i]++;
                }
            }
        }
        return output;
    }
};