// Problem 461: Hamming Distance
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp=x^y,answer=0;
        while(temp!=0){
            answer+=(temp&1);
            temp=temp>>1;
        }
        return answer;
    }
};