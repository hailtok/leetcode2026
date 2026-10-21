// Problem 435: Non-overlapping Intervals
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end(),compare);
        int pre=0,count=1;
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]>=intervals[pre][1]){
                pre=i;
                ++count;
            }
        }
        return intervals.size()-count;
    }
};