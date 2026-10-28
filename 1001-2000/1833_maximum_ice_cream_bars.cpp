// Problem 1833: Maximum Ice Cream Bars
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int output=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                coins-=costs[i];
                output++;
            }
            else{
                return output;
            }
        }
        return output;
    }
};