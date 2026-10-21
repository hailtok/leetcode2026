// Problem 1406: Stone Game III
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/stone-game-iii/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),INT_MIN);
        int n=stoneValue.size()-1;
        dp[n]=stoneValue[n];
        if(n-1>=0){
            dp[n-1]=stoneValue[n-1]+std::max(-dp[n],stoneValue[n]);
            if(n-2>=0){
                dp[n-2]=stoneValue[n-2]+std::max({-dp[n-1],stoneValue[n-1]-dp[n],stoneValue[n-1]+stoneValue[n]});
            }
        }
        for(int i=n-3;i>=0;--i){
            int max=INT_MIN;
            for(int j=0,sum=0;j<3;++j){
                sum+=stoneValue[i+j];
                max=std::max(sum-dp[i+j+1],max);
            }
            dp[i]=max;
        }
        if(dp[0]>0){
            return "Alice"; 
        }
        else if(dp[0]<0){
            return "Bob";
        }
        return "Tie";
    }
};