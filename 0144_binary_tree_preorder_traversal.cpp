// Problem 144: Binary Tree Preorder Traversal
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution {
public: 
    vector<int>answer;
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        answer.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return answer;
    }
};