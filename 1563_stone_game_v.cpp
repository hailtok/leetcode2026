// Problem 1563: Stone Game V
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/stone-game-v/

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        vector<vector<int>>dp(stoneValue.size(),vector<int>(stoneValue.size(),0));
        vector<int>prefix(stoneValue.size()+1,0);
        for(int i=0;i<prefix.size()-1;++i){
            prefix[i+1]=prefix[i]+stoneValue[i];
        }
        for(int i=1;i<stoneValue.size();++i){
            for(int j=i;j<stoneValue.size();++j){
                for(int k=j-i;k<j;++k){
                    int left=prefix[k+1]-prefix[j-i],right=prefix[j+1]-prefix[k+1];
                    if(left<right){
                        dp[j-i][j]=std::max(dp[j-i][j],left+dp[j-i][k]);
                    }
                    else if(left>right){
                        dp[j-i][j]=std::max(dp[j-i][j],right+dp[k+1][j]);
                    }
                    else{
                        int chooseLeft=left+dp[j-i][k];
                        int chooseRight=right+dp[k+1][j];
                        dp[j-i][j]=std::max({dp[j-i][j],chooseLeft,chooseRight});
                    }
                }
            }
        }
        return dp[0][stoneValue.size()-1];
    }
};