// Problem 3556: Sum of Largest Prime Substrings
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-largest-prime-substrings/

class Solution {
public:
    bool is_prime(long long n){
        if(n<=1){
            return false;
        }
        if(n==2){
            return true;
        }
        if(n%2==0){
            return false;
        }
        for(long long i=3;i*i<=n;i+=2){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        vector<long long>primes;
        for(int i=0;i<s.size();++i){
            for(int j=i+1;j<=s.size();++j){
                long long num=stoll(s.substr(i,j-i));
                if(is_prime(num)){
                    primes.push_back(num);
                }
            }
        }
        std::sort(primes.begin(),primes.end());
        long long ans=0,last=-1;
        for(int i=primes.size()-1,count=3;i>=0&&count>0;--i){
            if(primes[i]==last){
                continue;
            }
            --count;
            ans+=primes[i];
            last=primes[i];
        }
        return ans;
    }
};