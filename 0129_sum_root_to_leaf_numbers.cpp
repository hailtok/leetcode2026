// Problem 129: Sum Root to Leaf Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int total=0;
    void dfs(TreeNode* node,int value){
        value=value*10+node->val;
        if(node->right==NULL&&node->left==NULL){
            total+=value;
        }
        if(node->right!=NULL){
            dfs(node->right,value);
        }
        if(node->left!=NULL){
            dfs(node->left,value);
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return total;
    }
};