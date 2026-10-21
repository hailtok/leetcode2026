// Problem 452: Minimum Number of Arrows to Burst Balloons
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int last=points[0][1],answer=1;
        for(int i=1;i<points.size();++i){
            if(points[i][0]>last){
                answer++;
                last=points[i][1];
            }
            last=std::min(points[i][1],last);
        }
        return answer;
    }
};