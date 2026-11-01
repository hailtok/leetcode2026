// Problem 3783: Mirror Distance of an Integer
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/mirror-distance-of-an-integer/

class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n,t=0;
        while(n>0){
            t*=10;
            t+=n%10;
            n/=10;
        }
        return std::abs(temp-t);
    }
};