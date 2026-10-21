// Problem 112: Path Sum
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/path-sum/

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
    bool check=false;
    void dfs(TreeNode* node,int value){
        if(node==NULL){
            return;
        }
        if(value==node->val){
            if(node->right==NULL&&node->left==NULL){
                check=true;
                return;
            }
        }
        dfs(node->right,value-node->val);
        dfs(node->left,value-node->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return check;    
    }
};