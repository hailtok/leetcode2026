// Problem 123: Best Time to Buy and Sell Stock III
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>left(prices.size()),right(prices.size());
        left[0]=0;
        right[prices.size()-1]=0;
        int leftmin=prices[0],rightmax=prices[prices.size()-1],ans=0;
        for(int i=1,j=prices.size()-2;i<prices.size()&&j>=0;++i,--j){
            leftmin=std::min(leftmin,prices[i]);
            left[i]=std::max(left[i-1],prices[i]-leftmin);
            rightmax=std::max(rightmax,prices[j]);
            right[j]=std::max(right[j+1],rightmax-prices[j]);
        }
        for(int i=0;i<left.size();++i){
            ans=std::max(ans,left[i]+right[i]);
        }
        return ans;
    }
};