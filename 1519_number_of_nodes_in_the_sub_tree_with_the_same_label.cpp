// Problem 1519: Number of Nodes in the Sub-Tree With the Same Label
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution {
public:
    vector<int>answer;
    vector<int>parent;
    void recursion(int node,char cur_label,string labels){
        if(cur_label==labels[node]){
            answer[node]++;
        }
        if(node==0||parent[node]==-1){
            return;
        }
        recursion(parent[node],cur_label,labels);              
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        sort(edges[0].begin(),edges[0].end());
        answer=vector<int>(n);
        answer[0]++;
        parent=vector<int>(n,-1);
        for(int i=0;i<edges.size();i++){
            if(edges[i][1]==0){
                swap(edges[i][0],edges[i][1]);
            }
            if(parent[edges[i][1]]==-1){
                parent[edges[i][1]]=edges[i][0];  
            }
            else{
                parent[edges[i][0]]=edges[i][1];  
            }                         
        }
        for(int i=1;i<n;i++){
            if(parent[i]!=-1){
                recursion(i,labels[i],labels);
            }            
        }
        int zero=0;
        for(int i=0;i<n;i++){
            if(answer[i]==0){
                answer[i]++;
            }      
            if(labels[0]==labels[i]){
                zero++;
            }     
        }
        answer[0]=zero;
        return answer;
    }
};