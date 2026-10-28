// Problem 646: Maximum Length of Pair Chain
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>dp(pairs.size(),1);
        sort(pairs.begin(),pairs.end());
        dp[0]=1;
        for(int i=1;i<pairs.size();++i){
            for(int j=0;j<i;++j){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
        }
        int answer=INT_MIN;
        for(int i=0;i<pairs.size();++i){
            answer=max(answer,dp[i]);
        }
        return answer;
    }
};