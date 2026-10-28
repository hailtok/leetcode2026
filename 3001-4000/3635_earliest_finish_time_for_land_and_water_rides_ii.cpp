// Problem 3635: Earliest Finish Time for Land and Water Rides II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/

class Solution {
public:
    int caltime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd){
        int min=INT_MAX,ans=INT_MAX;
        for(int i=0;i<ls.size();++i){
            min=std::min(min,ls[i]+ld[i]);
        }
        for(int i=0;i<ws.size();++i){
            ans=std::min(ans,std::max(min,ws[i])+wd[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return std::min(caltime(landStartTime,landDuration,waterStartTime,waterDuration),caltime(waterStartTime,waterDuration,landStartTime,landDuration));
    }
};