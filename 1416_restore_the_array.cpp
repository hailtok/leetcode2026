// Problem 1416: Restore The Array
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/restore-the-array/

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int mod=1e9+7;
        vector<int>dp(s.size()+1,0);
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='0'){
                continue;
            }
            else{
                long long num=0;
                for(int j=i+1;j<dp.size();++j){
                    num*=10;
                    num+=(s[j-1]-'0');
                    if(num>k){
                        break;
                    }
                    dp[i]=(dp[i]+dp[j])%mod;
                }
            }
        }
        return dp[0];
    }
};