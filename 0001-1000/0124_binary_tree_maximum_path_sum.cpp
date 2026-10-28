// Problem 124: Binary Tree Maximum Path Sum
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int answer=INT_MIN;
    int dfs(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int left=dfs(node->left),right=dfs(node->right);
        answer=std::max(answer,node->val+left+right);
        return std::max(0,std::max()+node->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return answer;
    }
};