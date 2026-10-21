// Problem 226: Invert Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/invert-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node){
        if(node==NULL){
            return;
        }
        swap(node->right,node->left);
        dfs(node->right);
        dfs(node->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};