// Problem 980: Unique Paths III
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int goal=0,goal_i_index,goal_j_index,output=0;
    void recursion(vector<vector<int>>board,int i,int j,int count){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()){
            if(board[i][j]==-1||board[i][j]==1){
                return ;
            }
            else if(board[i][j]==2&&count==goal){
                output++;
            }
            else{
                board[i][j]=-1;
                recursion(board,i+1,j,count+1);
                recursion(board,i-1,j,count+1);
                recursion(board,i,j+1,count+1);
                recursion(board,i,j-1,count+1);
            }
        }
        else{
            return ;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int robot_i_index,robot_j_index;
        vector<vector<int>>board_template(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                board_template[i][j]=grid[i][j];
                if(grid[i][j]==0){
                    goal++;
                }
                else if(grid[i][j]==2){
                    goal_i_index=i;
                    goal_j_index=j;
                }
                else if(grid[i][j]==1){
                    robot_i_index=i;
                    robot_j_index=j;
                }
            }
        }
        recursion(board_template,robot_i_index+1,robot_j_index,0);
        recursion(board_template,robot_i_index-1,robot_j_index,0);
        recursion(board_template,robot_i_index,robot_j_index+1,0);
        recursion(board_template,robot_i_index,robot_j_index-1,0);
        return output;
    }
};