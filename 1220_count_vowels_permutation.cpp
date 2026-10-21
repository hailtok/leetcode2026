// Problem 1220: Count Vowels Permutation
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    int countVowelPermutation(int n) {
        long at,et,it,ot,ut;
        long a=1,e=1,i=1,o=1,u=1;
        for(int j=1;j<n;j++){
            at=(e+i+u)%1000000007;
            et=(a+i)%1000000007;
            it=(e+o)%1000000007;
            ot=i%1000000007;
            ut=(o+i)%1000000007;
            a=at,e=et,i=it,o=ot,u=ut;
        }
        return (a+e+i+o+u)%1000000007;
    }
};