// Problem 130: Surrounded Regions
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    static constexpr int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>&board,int x,int y){
        if(x<0||x==board.size()||y<0||y==board[0].size()||board[x][y]!='O'){
            return;
        }
        board[x][y]='A';
        for(int i=0;i<4;++i){
            dfs(board,x+dir[i][0],y+dir[i][1]);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int j=0;j<n;++j) {
            if(board[0][j]=='O'){
                dfs(board,0,j);
            }
            if(board[m-1][j]=='O'){
                dfs(board,m-1,j);
            }
        }
        for(int i=0;i<m;++i){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][n-1] =='O'){
                dfs(board,i,n-1);
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};