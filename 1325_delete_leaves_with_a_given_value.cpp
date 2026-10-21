// Problem 1325: Delete Leaves With a Given Value
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/delete-leaves-with-a-given-value/

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
    int goal;
    TreeNode* recursion(TreeNode* node){
        if(node==nullptr){
            return nullptr;
        }
        node->right=recursion(node->right);
        node->left=recursion(node->left);
        if(node->right==node->left&&node->val==goal){
            return nullptr;
        }
        else{
            return node;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        goal=target;
        return recursion(root);
    }
};