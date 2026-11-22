// Problem 2476: Closest Nodes Queries in a Binary Search Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/

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
    void dfs(TreeNode *node,vector<int>&arr){
        if(node==nullptr){
            return;
        }
        dfs(node->left,arr);
        arr.push_back(node->val);
        dfs(node->right,arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ans;
        vector<int>arr;
        dfs(root,arr);
        for(int i=0;i<queries.size();++i){
            int j=std::lower_bound(arr.begin(),arr.end(),queries[i])-arr.begin();
            if(j<arr.size()&&arr[j]==queries[i]){
                ans.push_back({queries[i],queries[i]});
            }
            else if(j==0){
                ans.push_back({-1,arr[j]});
            }
            else if(j==arr.size()){
                ans.push_back({arr[j-1],-1});
            }
            else{
                ans.push_back({arr[j-1],arr[j]});
            }
        }
        return ans;
    }
};