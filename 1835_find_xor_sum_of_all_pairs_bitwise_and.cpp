// Problem 1835: Find XOR Sum of All Pairs Bitwise AND
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor_arr1=0,xor_arr2=0;
        for(int arr:arr1){
            xor_arr1^=arr;
        }
        for(int arr:arr2){
            xor_arr2^=arr;
        }
        return xor_arr1&xor_arr2;
    }
};