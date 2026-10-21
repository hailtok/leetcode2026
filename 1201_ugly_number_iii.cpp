// Problem 1201: Ugly Number III
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/ugly-number-iii/

class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    long long lcm(int a,int b){
        return (long long)a*(long long)b/gcd(a,b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        int low=1,high=2*(int)1e9;
        long long A=a,B=b,C=c;
        long long ab=A*B/gcd(a,b),bc=B*C/gcd(b,c),ac=A*C/gcd(a,c);
        long long abc=a*bc/gcd(a,bc);
        while(low<high){
            int mid=low+(high-low)/2;
            int val=mid/A+mid/B+mid/C-mid/ab-mid/bc-mid/ac+mid/abc;
            if(val<n){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};