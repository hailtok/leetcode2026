// Problem 105: Construct Binary Tree from Preorder and Inorder Traversal
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    unordered_map<int,int>umap;
    TreeNode* recursion(int in_left,int in_right,int pre_left,int pre_right,vector<int> &preorder,vector<int> &inorder){
        if(in_left>in_right){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[pre_left]);
        if(in_left==in_right){
            return node;
        }
        int in_index=umap[preorder[pre_left]];
        int mid=pre_left+in_index-in_left;
        node->left=recursion(in_left,in_index-1,pre_left+1,mid,preorder,inorder);
        node->right=recursion(in_index+1,in_right,mid+1,pre_right,preorder,inorder);;
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=new TreeNode(preorder[0]);
        for(int i=0;i<preorder.size();++i){
            umap[inorder[i]]=i;
        }
        return recursion(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
};