// Problem 367: Valid Perfect Square
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=0,right=num;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long temp=(long long)mid*mid;
            if(temp==num){
                return true;
            }
            if(temp>num){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
};