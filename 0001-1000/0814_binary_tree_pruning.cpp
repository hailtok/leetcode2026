// Problem 814: Binary Tree Pruning
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    bool dfs(TreeNode* node){
        if(!node){
            return false;
        }
        bool left=dfs(node->left),right=dfs(node->right);
        if(!left){
            node->left=nullptr;
        }
        if(!right){
            node->right=nullptr;
        }
        if(node->val||left||right){
            return true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!dfs(root)){
            return nullptr;
        }
        return root;
    }
};