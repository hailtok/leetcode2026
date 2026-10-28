// Problem 543: Diameter of Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int ans=0;
    int dfs(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int left=dfs(node->left),right=dfs(node->right);
        ans=std::max(ans,left+right);
        return std::max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};