// Problem 57: Insert Interval
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>answer;
        bool check=false;
        if(intervals.size()==0){
            answer.push_back(newInterval);
            return answer;
        }
        for(int i=0;i<intervals.size();i++){
            if(!check){
                if(intervals[i][1]<newInterval[0]){
                    answer.push_back(intervals[i]);
                }
                else{
                    int start=intervals[i][0],end=newInterval[1],last=newInterval[1];
                    if(start>newInterval[0]){
                        start=newInterval[0];
                    }
                    while(i<intervals.size()&&end>=intervals[i][0]){
                        last=intervals[i][1];
                        i++;
                    }
                    if(last>end){
                        end=last;
                    }
                    answer.push_back({start,end});
                    if(i!=intervals.size()){
                        answer.push_back(intervals[i]);
                    }                    
                    check=true;
                }
            }
            else{
                answer.push_back(intervals[i]);
            }
        }
        if(intervals[intervals.size()-1][1]<newInterval[0]){
            answer.push_back(newInterval);
        }
        return answer;
    }
};