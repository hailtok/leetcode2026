// Problem 122: Best Time to Buy and Sell Stock II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer=0,previous=prices[0];
        for(int i=1;i<prices.size();i++){
            if(previous<prices[i]){
                answer+=prices[i]-previous;
                previous=prices[i];
            }
            else{
                previous=prices[i];
            }
        }
        return answer;
    }
};