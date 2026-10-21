// Problem 538: Convert BST to Greater Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* node){
        if(node==nullptr){
            return;
        }
        dfs(node->right);
        sum+=node->val;
        node->val=sum;
        dfs(node->left);
    }
};