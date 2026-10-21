// Problem 313: Super Ugly Number
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<unsigned>dp(n),primes_k(primes.size());
        dp[0]=1;
        for(int i=1;i<n;i++){
            unsigned temp=INT_MAX;
            for(int j=0;j<primes.size();j++){
                if(temp>primes[j]*dp[primes_k[j]]){
                    temp=primes[j]*dp[primes_k[j]];
                }   
            }
            for(int j=0;j<primes.size();j++){
                if(temp==primes[j]*dp[primes_k[j]]){
                    primes_k[j]++;
                }   
            }
            dp[i]=temp;
        }
        return dp[n-1];
    }
};