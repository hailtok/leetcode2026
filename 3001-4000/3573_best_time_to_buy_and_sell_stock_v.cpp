// Problem 3573: Best Time to Buy and Sell Stock V
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<long long>>no_stock(prices.size(),vector<long long>(k+1));
        vector<vector<long long>>with_stock(prices.size(),vector<long long>(k+1));
        vector<vector<long long>>sold_stock(prices.size(),vector<long long>(k+1));
        for(int j=1;j<=k;++j){
            with_stock[0][j]=-prices[0];
            sold_stock[0][j]=prices[0];
        }
        for(int i=1;i<prices.size();++i){
            for(int j=1;j<=k;++j){
                no_stock[i][j]=std::max({no_stock[i-1][j],with_stock[i-1][j]+prices[i],sold_stock[i-1][j]-prices[i]});
                with_stock[i][j]=std::max(with_stock[i-1][j],no_stock[i-1][j-1]-prices[i]);
                sold_stock[i][j]=std::max(sold_stock[i-1][j],no_stock[i-1][j-1]+prices[i]);
            }
        }
        return no_stock[prices.size()-1][k];
    }
};