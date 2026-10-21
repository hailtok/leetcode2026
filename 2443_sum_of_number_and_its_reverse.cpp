// Problem 2443: Sum of Number and Its Reverse
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-number-and-its-reverse/

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=0,number=i;i<=num;i++){
            int reverse=0;
            number=i;
            while(number>0){
                reverse*=10;
                reverse+=number%10;
                number/=10;
            }
            if(reverse+i==num){
                return true;
            }
        }
        return false;
    }
};