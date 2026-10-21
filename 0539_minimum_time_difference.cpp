// Problem 539: Minimum Time Difference
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>times(timePoints.size());
        for(int i=0;i<timePoints.size();i++){
            times[i]=((timePoints[i][0]-'0')*10+timePoints[i][1]-'0')*60+(timePoints[i][3]-'0')*10+timePoints[i][4]-'0';
        }
        sort(times.begin(),times.end());
        int answer=times[0]+1440-times[times.size()-1];
        for(int i=1;i<times.size();i++){
            answer=min(answer,times[i]-times[i-1]);
        }
        return answer;
    }
};