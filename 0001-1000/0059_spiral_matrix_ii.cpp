// Problem 59: Spiral Matrix II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir=0;
        vector<vector<int>>moves={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>answer(n,vector<int>(n));
        for(int i=1,row=0,col=0;i<=n*n;++i){
            answer[row][col]=i;
            if(row+moves[dir][0]>=n||row+moves[dir][0]<0||col+moves[dir][1]>=n||col+moves[dir][1]<0||answer[row+moves[dir][0]][col+moves[dir][1]]!=0){
                dir=(dir+1)%4;
            }
            row+=moves[dir][0];
            col+=moves[dir][1];
        }
        return answer;
    }
};