// Problem 134: Gas Station
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int start=0;start<gas.size();start++){
            int pass_station=0;
            int cur_gas=0;
            while(pass_station<gas.size()){
                int j=(start+pass_station)%gas.size();
                cur_gas+=gas[j];
                if(cur_gas<cost[j]){
                   break; 
                }
                else{
                    cur_gas-=cost[j];
                }
                pass_station++;
            }
            if(pass_station==gas.size()){
                return start;
            }
            start+=pass_station;
        }
        return -1;
    }
};