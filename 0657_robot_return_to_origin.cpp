// Problem 657: Robot Return to Origin
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>umap;
        for(int i=0;i<moves.size();++i){
            ++umap[moves[i]];
        }
        return umap['U']==umap['D']&&umap['L']==umap['R'];
    }
};