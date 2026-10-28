// Problem 110: Balanced Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/balanced-binary-tree/

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
    bool ans=true;
    int height_balanced(TreeNode* node,int depth){
        if(node==nullptr){
            return depth;
        }
        int left=height_balanced(node->left,depth+1),right=height_balanced(node->right,depth+1);
        if(std::max(left,right)>std::min(left,right)+1){
            ans=false;
        }
        return std::max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        height_balanced(root,0);
        return ans;
    }
};