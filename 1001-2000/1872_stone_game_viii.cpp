// Problem 1872: Stone Game VIII
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/stone-game-viii/

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int>dp(stones.size(),-1e9);
        vector<int>prefix(stones.size(),0);
        for(int i=0,sum=0;i<stones.size();++i){
            sum+=stones[i];
            prefix[i]=sum;
        }
        dp[stones.size()-1]=prefix[prefix.size()-1];
        for(int i=dp.size()-2;i>=1;--i){
            dp[i]=std::max(dp[i+1],prefix[i]-dp[i+1]);
        }
        return dp[1];
    }
};