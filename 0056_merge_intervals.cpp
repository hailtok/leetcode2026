// Problem 56: Merge Intervals
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>output;
        output.push_back(intervals[0]);
        for(int i=1,j=0;i<intervals.size();i++){
            if(output[j][1]>=intervals[i][0]){
                if(output[j][1]<intervals[i][1]){
                    output[j][1]=intervals[i][1];
                }
            }
            else{
                output.push_back(intervals[i]);
                j++;
            }
        }
        return output;
    }
};