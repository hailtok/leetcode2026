// Problem 1926: Nearest Exit from Entrance in Maze
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        static constexpr int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        queue<vector<int>>q;
        q.push({entrance[0],entrance[1],1});
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int next_x=cur[0]+dir[i][0],next_y=cur[1]+dir[i][1];
                if(next_x>=0&&next_x<maze.size()&&next_y>=0&&next_y<maze[0].size()){
                    if(maze[next_x][next_y]=='.'){
                        if(next_x==0||next_x==maze.size()-1||next_y==0||next_y==maze[0].size()-1){
                            return cur[2];
                        }
                        maze[next_x][next_y]='+';
                        q.push({next_x,next_y,cur[2]+1});
                    }
                }
            }
        }
        return -1;
    }
};