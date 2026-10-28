// Problem 79: Word Search
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/word-search/

class Solution {
public:
    vector<vector<int>>move={{-1,0},{0,-1},{1,0},{0,1}};
    bool dfs(vector<vector<char>>& board,int x,int y,string& word,int index){
        if(index==word.size()){
            return true;
        }
        char temp=board[x][y];
        board[x][y]='0';
        for(int i=0;i<move.size();++i){
            int new_x=x+move[i][0],new_y=y+move[i][1];
            if(new_x>=0&&new_x<board.size()&&new_y>=0&&new_y<board[0].size()&&board[new_x][new_y]==word[index]){               
                if(dfs(board,new_x,new_y,word,index+1)){
                    board[x][y]=temp;
                    return true;
                }
            }
        }
        board[x][y]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(word[0]==board[i][j]){
                    if(dfs(board,i,j,word,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};