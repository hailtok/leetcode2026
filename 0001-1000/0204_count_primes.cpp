// Problem 204: Count Primes
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool>primes(n+1,true);
        primes[0]=false;
        primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=2;i*j<=n;j++){
                    primes[i*j]=false;
                }
            }
        }
        int answer=0;
        for(int i=2;i<n;i++){
            if(primes[i]){
                answer++;
            }
        }
        return answer;
    }
};