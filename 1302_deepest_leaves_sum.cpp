// Problem 1302: Deepest Leaves Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/deepest-leaves-sum/

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
    int output=0,deepest=0;
    void recursion(TreeNode* node,int depth){
        if(node==nullptr){
            return;
        }
        if(node->right==nullptr&&node->left==nullptr&&deepest==depth){
            output+=node->val;
        }
        if(depth>deepest){
            output=node->val;
            deepest=depth;
        }
        recursion(node->right,depth+1);
        recursion(node->left,depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        recursion(root,0);
        return output;
    }
};