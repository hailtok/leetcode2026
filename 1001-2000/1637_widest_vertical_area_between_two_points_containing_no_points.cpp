// Problem 1637: Widest Vertical Area Between Two Points Containing No Points
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int output=0;
        for(int i=0;i<points.size()-1;i++){
            output=max(output,points[i+1][0]-points[i][0]);
        }
        return output;
    }
};