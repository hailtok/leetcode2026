// Problem 1861: Rotating the Box
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rotating-the-box/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>>answer(box[0].size(),vector<char>(box.size(),'.'));
        for(int i=0;i<box.size();++i){
            int leave=0,wall=box[0].size();
            for(int j=box[i].size()-1;j>=0;--j){
                if(box[i][j]=='*'){
                    answer[j][box.size()-i-1]='*';
                    while(leave){
                        answer[wall-1][box.size()-i-1]='#';
                        wall--;
                        leave--;
                    }
                    wall=j;
                    leave=0;
                }
                if(box[i][j]=='#'){
                    leave++;
                }
            }
            while(leave){
                answer[wall-1][box.size()-i-1]='#';
                leave--;
                wall--;
            }
        }
        return answer;
    }
};