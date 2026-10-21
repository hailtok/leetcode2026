// Problem 2415: Reverse Odd Levels of Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    void recursion(TreeNode* right_node,TreeNode* left_node,int depth){
        if(right_node==nullptr||left_node==nullptr){
            return;
        }
        if(depth%2==0){
            swap(right_node->val,left_node->val);
        }
        recursion(right_node->left,left_node->right,depth+1);
        recursion(right_node->right,left_node->left,depth+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        recursion(root->right,root->left,0);
        return root;
    }
};