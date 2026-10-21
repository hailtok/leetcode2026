// Problem 1884: Egg Drop With 2 Eggs and N Floors
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

class Solution {
public:
    int twoEggDrop(int n) {
        if(n==1){
            return 1;
        }
        int output=2;
        while((output+1)*output/2<n){
            output++;
        }
        return output;
    }
};