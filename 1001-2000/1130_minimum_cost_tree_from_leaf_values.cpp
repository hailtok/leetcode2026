// Problem 1130: Minimum Cost Tree From Leaf Values
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<pair<int,int>>>dp(arr.size(),vector<pair<int,int>>(arr.size(),{0,0}));
        for(int i=0;i<arr.size();i++)
        {
            dp[i][i].second=arr[i];
            for(int j=i+1;j<arr.size();j++)
            {
                dp[i][j].second=max(dp[i][j-1].second,arr[j]);
            }
        }
        for(int l=2;l<=arr.size();l++)
            for(int i=0;i<arr.size()-l+1;i++)
            {
                int j=i+l-1;
                dp[i][j].first=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    if(dp[i][j].first>dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second)
                    {
                        dp[i][j].first=dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second;   
                    }
            }
            }
        
        return dp[0][arr.size()-1].first;
    }
};