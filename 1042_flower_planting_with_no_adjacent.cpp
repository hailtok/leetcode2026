// Problem 1042: Flower Planting With No Adjacent
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/flower-planting-with-no-adjacent/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>ans(n,0);
        vector<vector<int>>count(n,vector<int>());
        for(int i=0;i<paths.size();++i){
            count[paths[i][0]-1].push_back(paths[i][1]-1);
            count[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        for(int i=0;i<count.size();++i){
            vector<bool>check(5,false);
            for(int j=0;j<count[i].size();++j){
                check[ans[count[i][j]]]=true;
            }
            for(int j=1;j<4;++j){
                if(!check[j]){
                    ans[i]=j;
                }
            }
        }
        for(int i=0;i<ans.size();++i){
            ans[i]=ans[i]%4+1;
        }
        return ans;
    }
};