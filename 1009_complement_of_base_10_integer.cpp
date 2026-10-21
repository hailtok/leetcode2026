// Problem 1009: Complement of Base 10 Integer
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask=1;
        while(mask<n){
            mask=(mask<<1)+1;
        }
        return mask^n;
    }
};