// Problem 701: Insert into a Binary Search Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution {
public:
    void dfs(TreeNode* node,int val){
        if(!node){
            return;
        }
        if(node->val>val){
            if(node->left==nullptr){
                node->left=new TreeNode(val);
            }
            else{
                dfs(node->left,val);
            }
        }
        else{
            if(node->right==nullptr){
                node->right=new TreeNode(val);
            }
            else{
                dfs(node->right,val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        dfs(root,val);
        return root;
    }
};