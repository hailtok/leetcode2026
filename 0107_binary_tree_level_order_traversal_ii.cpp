// Problem 107: Binary Tree Level Order Traversal II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>>answer;
    void dfs(TreeNode* node,int depth){
        if(node==NULL){
            return;
        }
        if(answer.size()==depth){
            answer.push_back(vector<int>());
        }
        answer[depth].push_back(node->val);
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root,0);
        reverse(answer.begin(),answer.end());
        return answer;
    }
};