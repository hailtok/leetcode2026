// Problem 1041: Robot Bounded In Circle
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int>count(4);
        int direction=0;
        for(int i=0;i<instructions.size();++i){
            if(instructions[i]=='G'){
                ++count[direction];
            }
            if(instructions[i]=='L'){
                direction=(direction+3)%4;
            }
            if(instructions[i]=='R'){
                direction=(direction+1)%4;
            }
        }
        if((count[0]==count[2]&&count[1]==count[3])||direction!=0){
            return true;
        }
        return false;
    }
};