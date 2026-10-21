// Problem 400: Nth Digit
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/nth-digit/

class Solution {
public:
    int findNthDigit(int n) {
        int start=1,count=1,ren=n;
        while((long long)start*9*count<(long long)n){
            ren-=start*9*count;
            start*=10;
            count++;
        }
        int number=start+(ren-1)/count,find=count-(ren-1)%count;
        for(int i=1;i<find;i++){
            number/=10;
        }
        return number%10;
    }
};