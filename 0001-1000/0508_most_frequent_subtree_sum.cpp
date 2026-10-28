// Problem 508: Most Frequent Subtree Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/most-frequent-subtree-sum/

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
    int dfs(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        int left=dfs(node->left),right=dfs(node->right);
        ++umap[node->val+left+right];
        return node->val+left+right;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int>ans;
        int count=0;
        for(auto it=umap.begin();it!=umap.end();++it){
            if(it->second==count){
                ans.push_back(it->first);
            }
            else if(it->second>count){
                count=it->second;
                ans.clear();
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};