// Problem 94: Binary Tree Inorder Traversal
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> answer;
    void dfs(TreeNode* node){
        if(node==NULL){
            return;
        }
        dfs(node->left);
        answer.push_back(node->val);
        dfs(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return answer;
    }
};