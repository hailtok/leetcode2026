// Problem 2265: Count Nodes Equal to Average of Subtree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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
    int count=0;
    pair<int,int> dfs(TreeNode* node){
        if(node==NULL){
            return {0,0};
        }
        int node_number=1;
        pair<int,int> right=dfs(node->right);
        pair<int,int> left=dfs(node->left);
        int left_sum=left.second,left_count=left.first,right_sum=right.second,right_count=right.first;
        if(node->val==(node->val+right_sum+left_sum)/(left_count+right_count+1)){
            count++;
        }
        return {(left_count+right_count+1),(node->val+right_sum+left_sum)};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};