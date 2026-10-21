// Problem 2125: Number of Laser Beams in a Bank
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last_laser=0,cur_laser=0,output=0;
        for(int i=0;i<bank.size();i++){
            for(int j=0;j<bank[i].size();j++){
                cur_laser+=bank[i][j]-'0';
            }
            if(cur_laser!=0){
                output+=last_laser*cur_laser;
                last_laser=cur_laser;
                cur_laser=0;
            }
        }
        return output;
    }
};