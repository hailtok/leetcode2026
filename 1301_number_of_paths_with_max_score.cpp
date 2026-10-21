// Problem 1301: Number of Paths with Max Score
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/number-of-paths-with-max-score/

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        vector<vector<int>>direction={{1,0},{0,1},{1,1}};
        vector<vector<int>>score(board.size(),vector<int>(board[0].size(),0)),path=score;
        int mod=1e9+7;
        path[0][0]=1;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(path[i][j]==0){
                    continue;
                }
                for(int k=0;k<direction.size();++k){
                    int new_i=i+direction[k][0],new_j=j+direction[k][1];
                    if(new_i==board.size()||new_j==board[0].size()||board[new_i][new_j]=='X'){
                        continue;
                    }
                    int sum=score[i][j];
                    if(board[new_i][new_j]!='S'){
                        sum+=board[new_i][new_j]-'0';
                    }
                    if(sum>score[new_i][new_j]){
                        score[new_i][new_j]=sum;
                        path[new_i][new_j]=path[i][j];
                    }
                    else if(sum==score[new_i][new_j]){
                        path[new_i][new_j]=(path[new_i][new_j]+path[i][j])%mod;
                    }
                }
            }
        }
        return {score[board.size()-1][board[0].size()-1],path[board.size()-1][board[0].size()-1]};
    }
};