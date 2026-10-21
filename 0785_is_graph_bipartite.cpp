// Problem 785: Is Graph Bipartite?
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool check(vector<vector<int>>&graph,vector<int>&color,int node,int col){
        if(color[node]!=0){
            return color[node]==col;
        }
        color[node]=col;
        for(int i=0;i<graph[node].size();++i){
            if(!check(graph,color,graph[node][i],-col)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),0);
        for(int i=0;i<graph.size();++i){
            if(color[i]==0&&!check(graph,color,i,1)){
                return false;
            }
        }
        return true;
    }
};