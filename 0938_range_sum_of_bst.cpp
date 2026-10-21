// Problem 938: Range Sum of BST
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    void dfs(TreeNode* node,int low,int high,int &sum){
        if(node==nullptr){
            return;
        }
        if(low<=node->val&&node->val<=high){
            sum+=node->val;
        }
        dfs(node->left,low,high,sum);
        dfs(node->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int total=0;
        dfs(root,low,high,total);
        return total;
    }
};