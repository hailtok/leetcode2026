// Problem 2331: Evaluate Boolean Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/evaluate-boolean-binary-tree/

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root){
            return false;
        }
        int left=evaluateTree(root->left),right=evaluateTree(root->right);
        if(root->val==0){
            return false;
        }
        else if(root->val==1){
            return true;
        }
        else if(root->val==2){
            return left||right;
        }
        else{
            return left&&right;
        }
    }
};