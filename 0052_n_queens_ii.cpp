// Problem 52: N-Queens II
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int total=0;
    void dfs(vector<vector<bool>>board,int queen){
        if(queen==0){
            total++;
            return;
        }
        for(int i=0;i<board.size();++i){
            if(board[board.size()-queen][i]){
                vector<vector<bool>>temp=board;
                cout<<"("<<board.size()-queen<<","<<i<<")"<<endl;
                for(int j=0;j<board.size();++j){
                    board[board.size()-queen][j]=false;
                    board[j][i]=false;
                }
                for(int j=1;i+j<board.size()&&board.size()-queen+j<board.size();++j){
                    board[board.size()-queen+j][i+j]=false;
                }
                for(int j=1;i-j>=0&&(int)board.size()-queen+j<board.size();++j){
                    board[board.size()-queen+j][i-j]=false;
                }
                dfs(board,queen-1);
                board=temp;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool>>dp(n,vector<bool>(n,true));
        dfs(dp,n);
        return total;
    }
};