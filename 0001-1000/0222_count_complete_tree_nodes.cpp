// Problem 222: Count Complete Tree Nodes
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
    int total=0;
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        total++;
        dfs(node->left);
        dfs(node->right);
    }
    int countNodes(TreeNode* root) {
        dfs(root);
        return total;
    }
};