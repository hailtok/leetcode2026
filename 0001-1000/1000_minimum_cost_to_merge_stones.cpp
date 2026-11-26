// Problem 1000: Minimum Cost to Merge Stones
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-cost-to-merge-stones/

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        if((stones.size()-1)%(k-1)!=0){
            return -1;
        }
        vector<int>prefix(stones.size()+1, 0);
        for (int i=0;i<stones.size();++i) {
            prefix[i+1]=prefix[i]+stones[i];
        }
        vector<vector<vector<int>>>dp(stones.size(),vector<vector<int>>(stones.size(),vector<int>(k+1,INT_MAX)));
        for (int i=0;i<stones.size();++i) {
            dp[i][i][1]=0;
        }
        for(int len=2;len<=stones.size();++len) {
            for (int i=0;i+len-1<stones.size();++i) {
                int j=i+len-1;
                for (int p=2;p<=k;++p) {
                    for (int mid=i;mid<j;mid+=k-1) {
                        if (dp[i][mid][1]<INT_MAX &&dp[mid+1][j][p-1]<INT_MAX) {
                            dp[i][j][p]=min(
                                dp[i][j][p],
                                dp[i][mid][1]+dp[mid+1][j][p-1]
                            );
                        }
                    }
                }
                if(dp[i][j][k]<INT_MAX) {
                    dp[i][j][1]=dp[i][j][k]+(prefix[j+1]-prefix[i]);
                }
            }
        }
        return dp[0][stones.size()-1][1];
    }
};