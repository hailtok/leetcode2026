// Problem 3319: K-th Largest Perfect Subtree Size in Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/

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
    vector<int>trees;
    int dfs(TreeNode* node,int &val){
        if(node==nullptr){
            return 0; 
        }
        int left=dfs(node->left,val),right=dfs(node->right,val);
        if(left==right){
            trees.push_back(left+right+1);
            return left+right+1;
        }
        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root,k);
        if(trees.size()==0||k>trees.size()){
            return -1;
        }
        std::sort(trees.begin(),trees.end());
        return trees[trees.size()-k];
    }
};