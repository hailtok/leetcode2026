// Problem 1992: Find All Groups of Farmland
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-all-groups-of-farmland/

class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&land,int x,int y){
        vector<int>square={x,y,0,0};
        int width=x,height=y;
        while(width<land.size()){
            if(land[width][height]!=1){
                break;
            }
            ++width;
        }
        --width;
        while(height<land[0].size()){
            if(land[width][height]!=1){
                break;
            }
            ++height;
        }
        --height;
        for(int i=x;i<width+1;++i){
            for(int j=y;j<height+1;++j){
                land[i][j]=0;
            }
        }
        square[2]=width;
        square[3]=height;
        ans.push_back(square);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        for(int i=0;i<land.size();++i){
            for(int j=0;j<land[0].size();++j){
                if(land[i][j]==1){
                    dfs(land,i,j);
                }
            }
        }
        return ans;
    }
};