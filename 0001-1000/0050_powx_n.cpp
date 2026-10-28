// Problem 50: Pow(x, n)
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double output=1;
        while(n!=0){
            if(n%2!=0){
                if(n>0){
                    output*=x;
                }
                else{
                    output/=x;
                }
            }
            x*=x;
            n/=2;
        }
        return output;
    }
};