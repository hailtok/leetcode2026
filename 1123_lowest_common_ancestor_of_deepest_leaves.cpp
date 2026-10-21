// Problem 1123: Lowest Common Ancestor of Deepest Leaves
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    int max_depth=0;
    TreeNode* ans=nullptr;
    int dfs(TreeNode* node,int depth){
        if(node==nullptr){
            return depth;
        }
        int left=dfs(node->left,depth+1),right=dfs(node->right,depth+1);
        if(left==right){
            if(left>=max_depth){
                ans=node;
                max_depth=left;
            }
        }
        return std::max(left,right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};