// Problem 589: N-ary Tree Preorder Traversal
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/n-ary-tree-preorder-traversal/

class Solution {
public:
    void dfs(vector<int>* answer,Node* node){
        if(!node){
            return;
        }
        answer->push_back(node->val);
        for(int i=0;i<node->children.size();++i){
            dfs(answer,node->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>answer;
        dfs(&answer,root);
        return answer;
    }
};