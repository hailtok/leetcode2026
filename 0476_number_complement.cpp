// Problem 476: Number Complement
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        long long  two_com=1;
        while(two_com<=num){
            two_com=two_com<<1;
        }
        return two_com-num-1;
    }
};