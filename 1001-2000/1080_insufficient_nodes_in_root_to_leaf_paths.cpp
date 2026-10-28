// Problem 1080: Insufficient Nodes in Root to Leaf Paths
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

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
    int dfs(TreeNode* node,int val,int& limit){
        if(node==nullptr){
            return limit;
        }
        int left=dfs(node->left,val+node->val,limit),right=dfs(node->right,val+node->val,limit);
        if(left<limit){
            node->left=nullptr;
        }
        if(right<limit){
            node->right=nullptr;
        }
        if(left==limit&&right==limit){
            if(node->val+val<limit){
                return INT_MIN;
            }
            return limit+1;
        }
        if((left==INT_MIN&&(right==INT_MIN||right==limit))||(right==INT_MIN&&(left==INT_MIN||left==limit))){
            return INT_MIN;
        }
        return limit+1;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        dfs(root,0,limit);
        if(root->left==nullptr&&root->right==nullptr&&root->val<limit){
            return nullptr;
        }
        return root;
    }
};