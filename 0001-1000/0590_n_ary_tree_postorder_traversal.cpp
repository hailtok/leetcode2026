// Problem 590: N-ary Tree Postorder Traversal
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/n-ary-tree-postorder-traversal/

class Solution {
public:
    void dfs(vector<int>* answer,Node* node){
        if(!node){
            return;
        }
        for(int i=0;i<node->children.size();++i){
            dfs(answer,node->children[i]);
        }
        answer->push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>answer;
        dfs(&answer,root);
        return answer;
    }
};