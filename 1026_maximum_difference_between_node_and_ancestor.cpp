// Problem 1026: Maximum Difference Between Node and Ancestor
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

class Solution {
public:
    int max_diff=INT_MIN;
    void dfs(TreeNode* node,vector<int> ancestor){
        if(node==nullptr){
            return;
        }
        for(int i=0;i<ancestor.size();++i){
            max_diff=std::max(std::abs(node->val-ancestor[i]),max_diff);
        }
        ancestor.push_back(node->val);
        dfs(node->left,ancestor);
        dfs(node->right,ancestor);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,vector<int>(0));
        return max_diff;
    }
};