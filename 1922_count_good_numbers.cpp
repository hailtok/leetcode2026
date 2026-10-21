// Problem 1922: Count Good Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-good-numbers/

class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod=1e9+7;
        long long ans=0,odd_temp=1,even_temp=1,odd=n/2,even=n-odd;
        for(long long pow=4;odd!=0;pow=pow*pow%mod){
            if(odd%2!=0){
                odd_temp*=pow;
                odd_temp%=mod;
            }
            odd>>=1;
        }
        for(long long pow=5;even!=0;pow=pow*pow%mod){
            if(even%2!=0){
                even_temp*=pow;
                even_temp%=mod;
            }
            even>>=1;
        }
        ans+=odd_temp*even_temp%mod;
        return ans;
    }
};