// Problem 3871: Count Commas in Range II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-commas-in-range-ii/

class Solution {
public:
    long long countCommas(long long n) {
        int count=1;
        long long mod=999,ans=0;
        while(n>mod){
            ans+=(n-mod)*count;
            mod=mod*1000+999;
        }
        return ans;
    }
};