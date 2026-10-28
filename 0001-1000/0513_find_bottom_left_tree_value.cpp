// Problem 513: Find Bottom Left Tree Value
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int depth=0,output=INT_MAX;
    void recursion(TreeNode* node,int dep){
        if(node==nullptr){
            return;
        }
        if(dep>=depth){
            output=node->val;
            depth=dep;
        }
        recursion(node->right,dep+1);
        recursion(node->left,dep+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        recursion(root,0);
        return output;
    }
};