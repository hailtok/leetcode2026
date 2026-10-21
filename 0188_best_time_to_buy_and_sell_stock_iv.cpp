// Problem 188: Best Time to Buy and Sell Stock IV
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>buy(prices.size(),vector<int>(k+1));
        vector<vector<int>>sell(prices.size(),vector<int>(k+1));
        for(int i=0;i<prices.size();++i){
            for(int j=0;j<=k;++j){
                buy[i][j]=-prices[0];
            }
        }
        for(int i=1;i<prices.size();++i){
            for(int j=1;j<=k;++j){
                buy[i][j]=std::max(sell[i-1][j-1]-prices[i],buy[i-1][j]);
                sell[i][j]=std::max(buy[i-1][j]+prices[i],sell[i-1][j]);
            }
        }
        return sell[prices.size()-1][k];
    }
};