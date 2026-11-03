// Problem 3360: Stone Removal Game
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/stone-removal-game/

class Solution {
public:
    bool canAliceWin(int n) {
        bool win=false;
        int stone=10;
        while(n>=stone){
            n-=stone;
            --stone;
            win=!win;
        }
        return win;
    }
};