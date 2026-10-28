// Problem 1701: Average Waiting Time
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/average-waiting-time/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double output=0,begin=0;
        for(int i=0;i<customers.size();i++){
            if(begin>customers[i][0]){
                output+=begin-customers[i][0];
            }
            else{
                begin=customers[i][0];
            }
            begin+=customers[i][1];
            output+=customers[i][1];
        }
        return output/customers.size();
    }
};