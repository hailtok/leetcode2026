// Problem 450: Delete Node in a BST
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        else{
            if(root->val>key){
                root->left=deleteNode(root->left,key);
            }
            else if(root->val<key){
                root->right=deleteNode(root->right,key);
            }
            else{
                if(root->right==NULL&&root->left==NULL){
                    return NULL;
                }
                if(root->left==NULL){
                    return root->right;
                }
                if(root->right==NULL){
                    return root->left;
                }             
                TreeNode* temp=root->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                root->val=temp->val;
                root->left=deleteNode(root->left,temp->val);
            }
        }
        return root;
    }
};