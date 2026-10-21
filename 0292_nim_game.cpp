// Problem 292: Nim Game
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/nim-game/

class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0){
            return false;
        }
        return true;
    }
};