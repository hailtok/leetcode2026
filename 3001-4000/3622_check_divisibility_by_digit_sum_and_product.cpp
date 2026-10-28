// Problem 3622: Check Divisibility by Digit Sum and Product
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,product=1,n1=n;
        while(n>0){
            sum+=n%10;
            product*=n%10;
            n/=10;
        }
        return n1%(sum+product)==0;
    }
};