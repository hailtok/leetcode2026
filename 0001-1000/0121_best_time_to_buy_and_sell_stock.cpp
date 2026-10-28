// Problem 121: Best Time to Buy and Sell Stock
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer=0,temp=INT_MAX;
        for(int i=0;i<prices.size();i++){
            answer=max(prices[i]-temp,answer);
            temp=min(temp,prices[i]);
        }
        return answer;
    }
};