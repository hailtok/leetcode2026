// Problem 289: Game of Life
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>move={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
        vector<vector<int>>ans(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                int live=0;
                for(int k=0;k<move.size();++k){
                    int new_x=i+move[k][0],new_y=j+move[k][1];
                    if(new_x>=0&&new_x<board.size()&&new_y>=0&&new_y<board[0].size()&&board[new_x][new_y]==1){
                        ++live;
                    }
                }
                if(board[i][j]==1){
                    if(live<2||live>3){
                        ans[i][j]=0;
                    }
                    else{
                        ans[i][j]=1;
                    }
                }
                else{
                    if(live==3){
                        ans[i][j]=1;
                    }
                    else{
                        ans[i][j]=0;
                    }
                }
            }
        }
        board=ans;
    }
};