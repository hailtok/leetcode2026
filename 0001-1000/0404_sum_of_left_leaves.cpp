// Problem 404: Sum of Left Leaves
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-left-leaves/

class Solution {
public:
    int dfs(TreeNode* node,int& total){
        if(node==nullptr){
            return 0;
        }
        if(node->left==nullptr&&node->right==nullptr){
            return node->val;
        }
        total+=dfs(node->left,total);
        dfs(node->right,total);
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int total=0;
        dfs(root,total);
        return total;
    }
};