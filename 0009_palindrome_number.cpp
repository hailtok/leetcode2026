// Problem 9: Palindrome Number
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long temp=0;
        int temp2=x;
        while(x!=0){
            temp*=10;
            temp+=x%10;
            x/=10;
        }
        if(temp==temp2){
            return true;
        }
        return false;
    }
};