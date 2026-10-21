// Problem 201: Bitwise AND of Numbers Range
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left>0){
            if(left!=right){
                count++;
            }
            else{
                break;
            }
            left>>=1;
            right>>=1;
        }
        if(left==0){
            return 0;
        }
        while(count--){
            right<<=1;
        }
        return right;
    }
};