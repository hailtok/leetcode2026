// Problem 104: Maximum Depth of Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int dfs(TreeNode* node,int depth){
        if(node==NULL){
            return depth;
        }
        return max(dfs(node->right,depth+1),dfs(node->left,depth+1));
    }
    int maxDepth(TreeNode* root) {
        return dfs(root,0);
    }
};