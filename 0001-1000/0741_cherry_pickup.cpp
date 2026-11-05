// Problem 741: Cherry Pickup
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid.size(),-1));
        dp[0][0]=grid[0][0];
        int total_step=grid.size()*2-1;
        for(int k=1;k<total_step;++k){
            for(int i=grid.size()-1;i>=0;--i){
                for(int p=grid.size()-1;p>=0;--p){
                    int j=k-i,q=k-p;
                    if(j<0||j>=grid.size()||q<0||q>=grid.size()||grid[i][j]<0||grid[p][q]<0){
                        dp[i][p]=-1;
                        continue;
                    }
                    if(i>0){
                        dp[i][p]=std::max(dp[i][p],dp[i-1][p]);
                    }
                    if(p>0){
                        dp[i][p]=std::max(dp[i][p],dp[i][p-1]);
                    }
                    if(i>0&&p>0){
                        dp[i][p]=std::max(dp[i][p],dp[i-1][p-1]);
                    }
                    if(dp[i][p]>=0){
                        dp[i][p]+=grid[i][j]+(i!=p?grid[p][q]:0);
                    }
                }
            }
        }
        return std::max(0,dp[dp.size()-1][dp.size()-1]);
    }
};