// Problem 309: Best Time to Buy and Sell Stock with Cooldown
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>buy(prices.size(),0),sell(prices.size(),0),cool(prices.size(),0);
        buy[0]=-prices[0];
        for(int i=1;i<prices.size();++i){
            buy[i]=std::max(cool[i-1]-prices[i],buy[i-1]);
            sell[i]=std::max(buy[i-1]+prices[i],sell[i-1]);
            cool[i]=std::max(std::max(buy[i-1],sell[i-1]),cool[i-1]);
        }
        return sell[prices.size()-1];
    }
};