// Problem 36: Valid Sudoku
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<bool>column_check(9);
            vector<bool>row_check(9);
            vector<bool>square_check(9);
            for(int j=0;j<9;j++){
                if(isdigit(board[i][j])){
                    if(column_check[board[i][j]-'1']){
                        return false; 
                    }
                    else{
                        column_check[board[i][j]-'1']=true;
                    }   
                }
                if(isdigit(board[j][i])){
                    if(row_check[board[j][i]-'1']){
                        return false; 
                    }
                    else{
                        row_check[board[j][i]-'1']=true;
                    }   
                }
                if(isdigit(board[i/3*3+j/3][i%3*3+j%3])){
                    if(square_check[board[i/3*3+j/3][i%3*3+j%3]-'1']){
                        return false; 
                    }
                    else{
                        square_check[board[i/3*3+j/3][i%3*3+j%3]-'1']=true;
                    }   
                }
            }
        }
        return true;
    }
};