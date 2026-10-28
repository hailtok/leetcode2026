// Problem 475: Heaters
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/heaters/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int radius=INT_MIN,heater_index=0;
        for(int i=0;i<houses.size();i++){
            while(heater_index<heaters.size()-1&&abs(houses[i]-heaters[heater_index+1])<=abs(houses[i]-heaters[heater_index])){
                heater_index++;
            }
            radius=max(radius,abs(houses[i]-heaters[heater_index]));
        }
        return radius;
    }
};