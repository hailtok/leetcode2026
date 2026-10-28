// Problem 2400: Number of Ways to Reach a Position After Exactly k Steps
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int mod=1e9+7,s= (k-abs(endPos - startPos))/2;;
        if(abs(endPos-startPos)>k||(k-abs(endPos-startPos))%2!=0){
            return 0;
        }
        vector<int> dp(s+1, 1);
        for(int i=0;i<k-s;++i){
            for(int j=1;j<s+1;j++){
                dp[j] = (dp[j] + dp[j-1]) % mod;
            }
        }
        return dp[s];
    }
};