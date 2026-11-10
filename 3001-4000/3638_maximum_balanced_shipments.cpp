// Problem 3638: Maximum Balanced Shipments
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-balanced-shipments/

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int pre=0,ans=0;
        for(int i=0;i<weight.size();++i){
            if(pre>weight[i]){
                pre=0;
                ++ans;
            }
            else{
                pre=weight[i];
            }
        }
        return ans;
    }
};