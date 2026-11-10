// Problem 866: Prime Palindrome
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/prime-palindrome/

class Solution {
public:
    bool isPrime(int n){
        if(n<2){
            return false;
        }
        if(n==2||n==3){
            return true;
        }
        if(n%2==0||n%3==0){
            return false;
        }
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0||n%(i+2)==0){
                return false;
            }
        }
        return true;
    }
    int primePalindrome(int n) {
        if(n<=2){
            return 2;
        }
        if(n<=3){
            return 3;
        }
        if(n<=5){
            return 5;
        }
        if(n<=7){
            return 7;
        }
        if(n<=11){
            return 11;
        }
        for (int i=10;i<10000;++i) {
            std::string s=std::to_string(i);
            std::string r(s.rbegin(),s.rend());
            std::string palStr=s+r.substr(1);
            long long p=std::stoll(palStr);
            if (p>=n&&isPrime(p)) {
                return p;
            }
        }
        for (int i=10000;i<100000;++i) {
            std::string s=std::to_string(i);
            std::string r(s.rbegin(),s.rend());
            std::string palStr=s+r.substr(1);
            long long p =std::stoll(palStr);
            if (p>=n&&isPrime(p)) {
                return p;
            }
        }
        return -1;
    }
};