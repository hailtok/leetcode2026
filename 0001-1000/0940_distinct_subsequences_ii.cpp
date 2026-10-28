// Problem 940: Distinct Subsequences II
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        long long total=0;
        vector<long long>dp(26);
        for(int i=0;i<s.size();++i){
            long long current_added=(total + 1)%mod;
            total=(total+current_added)%mod;
            total=(total-dp[s[i]-'a']+mod)%mod;
            dp[s[i]-'a']=current_added;
        }
        return (int)total;
    }
};