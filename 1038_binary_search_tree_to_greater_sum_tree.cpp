// Problem 1038: Binary Search Tree to Greater Sum Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

class Solution {
public:
    int dfs(TreeNode* node,int value){
        if(node==nullptr){
            return value;
        }
        node->val+=dfs(node->right,value);
        return dfs(node->left,node->val);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root,0);
        return root;
    }
};