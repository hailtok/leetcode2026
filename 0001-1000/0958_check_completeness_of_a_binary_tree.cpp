// Problem 958: Check Completeness of a Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/check-completeness-of-a-binary-tree/

class Solution {
public:
    unsigned long long check=INT_MAX,exist=0;
    void dfs(TreeNode* node,unsigned long long position){
        if(!node){
            check=std::min(check,position);
            return;
        }
        exist=std::max(exist,position);
        dfs(node->left,position*2);
        dfs(node->right,position*2+1);
    }
    bool isCompleteTree(TreeNode* root) {
        dfs(root,1);
        return check>exist?true:false;
    }
};