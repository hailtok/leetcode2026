// Problem 834: Sum of Distances in Tree
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:
    void child_dfs(vector<vector<int>>&E,vector<int>&child,int parent,int node_val){
        for(int i=0;i<E[node_val].size();++i){
            if(E[node_val][i]!=parent){
                child_dfs(E,child,node_val,E[node_val][i]);
                child[node_val]+=child[E[node_val][i]];
            }
        }
        child[node_val]+=E[node_val].size()-1;
        if(parent==-1){
            child[node_val]++;
        }
    }
    void dfs_val(vector<vector<int>>&E,vector<int>&child,vector<int>&answer,int parent,int node_val){
        if(parent!=-1){
            answer[node_val]=answer[parent]-child[node_val]+(child.size()-child[node_val]-2);
        }
        for(int i=0;i<E[node_val].size();++i){
            if(E[node_val][i]!=parent){
                dfs_val(E,child,answer,node_val,E[node_val][i]);
            }
        }
    }
    int dfs(vector<vector<int>>&E,int parent,int node_val,int depth){
        int value=depth;
        for(int i=0;i<E[node_val].size();++i){
            if(E[node_val][i]!=parent){
                value+=dfs(E,node_val,E[node_val][i],depth+1);
            }
        }
        return value;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n<=1){
            return vector<int>(1,0);
        }
        vector<vector<int>>E(n,vector<int>());
        vector<int>child(n,0);
        for(int i=0;i<edges.size();++i){
            E[edges[i][0]].push_back(edges[i][1]);
            E[edges[i][1]].push_back(edges[i][0]);
        }
        int root=-1;
        for(int i=0;i<E.size();++i){
            if(E[i].size()==1){
                root=i;
                break;
            }
        }
        vector<int>answer(n);
        answer[root]=dfs(E,-1,root,0);
        child_dfs(E,child,-1,root);
        dfs_val(E,child,answer,-1,root);
        return answer;
    }
};