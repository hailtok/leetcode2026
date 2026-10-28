// Problem 101: Symmetric Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/symmetric-tree/

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
    bool check=true;
    void dfs(TreeNode* node1,TreeNode* node2){
        if(node1==NULL||node2==NULL){
            if(node1!=node2){
                check=false;
            }
            return;
        }
        if(node1->val!=node2->val){
            check=false;
            return;
        }
        dfs(node1->right,node2->left);
        dfs(node1->left,node2->right);
    }
    bool isSymmetric(TreeNode* root) {
        dfs(root->right,root->left);
        return check;
    }
};