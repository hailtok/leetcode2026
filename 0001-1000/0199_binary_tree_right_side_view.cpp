// Problem 199: Binary Tree Right Side View
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int>answer;
    void dfs(TreeNode* node,int depth){
        if(node==nullptr){
            return;
        }
        if(depth>=answer.size()){
            answer.push_back(INT_MIN);
        }
        answer[depth]=node->val;
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return answer;
    }
};