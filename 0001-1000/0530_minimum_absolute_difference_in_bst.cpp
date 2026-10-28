// Problem 530: Minimum Absolute Difference in BST
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    vector<int>arr;
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        dfs(node->left);
        arr.push_back(node->val);
        dfs(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int ans=INT_MAX;
        for(int i=1;i<arr.size();++i){
            ans=std::min(ans,arr[i]-arr[i-1]);
        }
        return ans;
    }
};