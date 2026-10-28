// Problem 114: Flatten Binary Tree to Linked List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    vector<int>temp;
    void dfs(TreeNode* node){
        if(node==NULL){
            return;
        }
        temp.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        dfs(root);
        root->left=NULL;
        for(int i=1;i<temp.size();i++){
            TreeNode* node=new TreeNode(temp[i]);
            root->right=node;
            root=root->right;
        }
    }
};