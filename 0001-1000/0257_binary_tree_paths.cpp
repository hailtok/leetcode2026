// Problem 257: Binary Tree Paths
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-paths/

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
    vector<string>output;
    void dfs(TreeNode* node,string order){
        if(node==NULL){
            return;
        }
        if(node->right==nullptr&&node->left==nullptr){
            output.push_back(order);
            return;
        }
        if(node->right!=nullptr){
            dfs(node->right,order+"->"+to_string(node->right->val));
        }
        if(node->left!=nullptr){
            dfs(node->left,order+"->"+to_string(node->left->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,to_string(root->val));
        return output;
    }
};