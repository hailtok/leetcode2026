// Problem 2144: Minimum Cost of Buying Candies With Discount
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.begin(),cost.end(),greater<int>());
        int ans=0,size=cost.size()/3;
        for(int i=0;i<size;++i){
            ans+=cost[i*3]+cost[i*3+1];
        }
        int index=0;
        while(size*3+index<cost.size()){
            ans+=cost[size*3+index];
            ++index;
        }
        return ans;
    }
};