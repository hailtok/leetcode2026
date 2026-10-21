// Problem 1448: Count Good Nodes in Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int find_node(TreeNode* node,int max){
        if(node==NULL){
            return 0;
        }
        if(node->val>=max){
            return 1+find_node(node->left,node->val)+find_node(node->right,node->val);
        }
        else{
            return find_node(node->left,max)+find_node(node->right,max);
        }
    }
    int goodNodes(TreeNode* root) {
        return find_node(root,root->val);
    }
};