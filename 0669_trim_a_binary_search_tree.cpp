// Problem 669: Trim a Binary Search Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/trim-a-binary-search-tree/

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
    TreeNode* dfs(TreeNode* node,int &low,int& high){
        if(node==nullptr){
            return nullptr;
        }
        node->left=dfs(node->left,low,high);
        node->right=dfs(node->right,low,high);
        if(low<=node->val&&node->val<=high){
            return node;
        }
        return node->left?node->left:node->right;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root,low,high);
    }
};