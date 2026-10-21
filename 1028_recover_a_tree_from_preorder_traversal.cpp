// Problem 1028: Recover a Tree From Preorder Traversal
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

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
    void dfs(TreeNode *node,string& path,int* index,int depth){
        int num=0;
        while(isdigit(path[*index])){
            num*=10;
            num+=path[*index]-'0';
            (*index)++;
        }
        node->val=num;
        int next_depth=0;
        while(path[*index]=='-'){
            next_depth++;
            (*index)++;
        }
        if(next_depth==depth+1){
            node->left=new TreeNode(0);
            dfs(node->left,path,index,depth+1);
        }
        else{
            (*index)-=next_depth;
            return;
        }
        next_depth=0;
        while(path[*index]=='-'){
            next_depth++;
            (*index)++;
        }
        if(next_depth==depth+1){
            node->right=new TreeNode(0);
            dfs(node->right,path,index,depth+1);
        }
        else{
            (*index)-=next_depth;
            return;
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root=new TreeNode(0);
        int index=0;
        dfs(root,traversal,&index,0);
        return root;
    }
};