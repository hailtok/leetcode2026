// Problem 337: House Robber III
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/house-robber-iii/

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
    pair<int,int>dfs(TreeNode* node){
        if(node==nullptr){
            return {0,0};
        }
        pair<int,int>left=dfs(node->left),right=dfs(node->right);
        return {std::max(node->val+left.second+right.second,left.first+right.first),left.first+right.first};
    }
    int rob(TreeNode* root) {
        pair<int,int>ans=dfs(root);
        return ans.first;
    }
};