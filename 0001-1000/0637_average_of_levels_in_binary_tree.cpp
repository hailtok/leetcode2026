// Problem 637: Average of Levels in Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double>output;
    vector<int>depth_count;
    void dfs(TreeNode* node,int depth){
        if(node==NULL){
            return;
        }
        if(depth==output.size()){
            output.push_back(node->val);
            depth_count.push_back(1);
        }
        else{
            output[depth]+=node->val;
            depth_count[depth]++;
        }
        dfs(node->right,depth+1);
        dfs(node->left,depth+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root,0);
        for(int i=0;i<depth_count.size();i++){
            output[i]/=depth_count[i];
        }
        return output;
    }
};