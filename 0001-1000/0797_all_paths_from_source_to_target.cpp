// Problem 797: All Paths From Source to Target
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    int end;
    vector<vector<int>>output;
    vector<int>temp;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        end=graph.size()-1;
        dfs(graph,0);
        return output;
    }
    void dfs(vector<vector<int>>graph,int node){
        temp.push_back(node);
        if(node==end){
            output.push_back(temp);
        }
        else{
            for(int i=0;i<graph[node].size();i++){
                dfs(graph,graph[node][i]);
            }
        }
        temp.pop_back();
    }
};