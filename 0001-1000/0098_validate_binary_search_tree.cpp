// Problem 98: Validate Binary Search Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        return check_node(root,LONG_MAX,LONG_MIN);
    }
    bool check_node(TreeNode* node,long max,long min){
        if(!node){
            return true;
        }
        if(node->val>min&&node->val<max){
            return check_node(node->left,node->val,min)&&check_node(node->right,max,node->val);
        }
        else{
            return false;
        }
    }
};