// Problem 390: Elimination Game
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/elimination-game/

class Solution {
public:
    int lastRemaining(int n) {
        int remaining=n;
        int start=1,count=1;
        bool change=true;
        while(remaining>1){
            if(change||remaining%2==1){
                start+=count;
            }
            count*=2;
            remaining/=2;
            change=!change;
        }
        return start;
    }

};