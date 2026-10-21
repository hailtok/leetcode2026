// Problem 145: Binary Tree Postorder Traversal
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    void dfs(vector<int>&ans,TreeNode* node){
        if(node==nullptr){
            return;
        }
        dfs(ans,node->left);
        dfs(ans,node->right);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs(ans,root);
        return ans;
    }
};