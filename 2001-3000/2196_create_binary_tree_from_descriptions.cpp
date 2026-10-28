// Problem 2196: Create Binary Tree From Descriptions
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/create-binary-tree-from-descriptions/

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int>parents;
        unordered_map<int,TreeNode*>umap;
        for(int i=0;i<descriptions.size();++i){
            TreeNode* node=umap.find(descriptions[i][0])==umap.end()?new TreeNode(descriptions[i][0]):umap[descriptions[i][0]];
            TreeNode* child=umap.find(descriptions[i][1])==umap.end()?new TreeNode(descriptions[i][1]):umap[descriptions[i][1]];
            if(descriptions[i][2]==1){
                node->left=child;
            }
            else{
                node->right=child;
            }
            parents[descriptions[i][1]]=descriptions[i][0];
            umap[descriptions[i][0]]=node;
            umap[descriptions[i][1]]=child;
        }
        TreeNode* root=nullptr;
        for(int i=0;i<descriptions.size();++i){
            if(parents.find(descriptions[i][0])==parents.end()){
                root=umap[descriptions[i][0]];
                break;
            }
        }
        return root;
    }
};