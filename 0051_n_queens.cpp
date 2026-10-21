// Problem 51: N-Queens
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> answer;
    int limit;
    void dfs(int queen,vector<string>&chess){
        if(queen==limit){
            answer.push_back(chess);
            return ;
        }
        for(int i=0;i<chess.size();++i){
            bool check=false;
            for(int j=1;i-j>=0&&queen-j>=0;++j){
                if(chess[queen-j][i-j]=='Q'){
                    check=true;
                    break;
                }
            }
            for(int j=1;queen-j>=0;++j){
                if(chess[queen-j][i]=='Q'){
                    check=true;
                    break;
                }
            }
            for(int j=1;i+j<chess.size()&&queen-j>=0;++j){
                if(chess[queen-j][i+j]=='Q'){
                    check=true;
                    break;
                }
            }
            if(check){
                continue;
            }
            chess[queen][i]='Q';
            dfs(queen+1,chess);
            chess[queen][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        limit=n;
        vector<string>chess(n,string(n, '.'));
        dfs(0,chess);
        return answer;
    }
};