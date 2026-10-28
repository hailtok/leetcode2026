// Problem 554: Brick Wall
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/brick-wall/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        for(int i=0;i<wall.size();i++){
            int total=0;
            for(int j=0;j<wall[i].size()-1;j++){
                total+=wall[i][j];
                edges[total]++;
            }
        }
        int output=0;
        for(unordered_map<int,int>::iterator it=edges.begin();it!=edges.end();it++){
            if(output<it->second){
                output=it->second;
            }
        }
        return wall.size()-output;
    }
};