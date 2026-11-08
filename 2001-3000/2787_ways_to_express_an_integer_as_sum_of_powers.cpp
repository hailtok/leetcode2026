// Problem 2787: Ways to Express an Integer as Sum of Powers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/

class Solution {
public:
    static constexpr int mod=1e9+7;
    int numberOfWays(int n, int x) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;;++i) {
            long long val = 1;
            for(int k=0;k<x;++k) {
                val*=i;
            }
            if(val>n){
                break;
            }
            for(int w=n;w>=val;--w) {
                dp[w]=(dp[w]+dp[w-(int)val])%mod;
            }
        }
        return dp[n];
    }
};