// Problem 1288: Remove Covered Intervals
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int output=1,begin=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(begin<intervals[i][0]&&end<intervals[i][1]){
                output++;
            }
            if(intervals[i][1]>end){
                begin=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return output;
    }
};