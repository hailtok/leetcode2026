// Problem 113: Path Sum II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/path-sum-ii/

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
    void dfs(TreeNode* node, int val,vector<int>path){
        if(node==NULL){
            return;
        }
        if(!(node -> left) && !(node -> right) && val == node->val){
            path.push_back(node->val);
            answer.push_back(path);
            return;
        }
        path.push_back(node->val);
        dfs(node->right,val-node->val,path);
        dfs(node->left,val-node->val,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,vector<int>());
        return answer;
    }
};