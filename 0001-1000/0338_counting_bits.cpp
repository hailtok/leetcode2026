// Problem 338: Counting Bits
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>output(num+1);
        for(int i=1;i<output.size();i++){
            output[i]=output[i/2]+(i%2);
        }
        return output;
    }
};