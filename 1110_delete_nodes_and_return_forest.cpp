// Problem 1110: Delete Nodes And Return Forest
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/delete-nodes-and-return-forest/

class Solution {
public:
    vector<TreeNode*>ans;
    bool dfs(TreeNode *node,vector<int>&to_delete){
        if(node==nullptr){
            return false;
        }
        if(dfs(node->left,to_delete)){
            node->left=nullptr;
        }
        if(dfs(node->right,to_delete)){
            node->right=nullptr;
        }
        if(std::binary_search(to_delete.begin(),to_delete.end(),node->val)){
            if(node->left!=nullptr){
                ans.push_back(node->left);
            }
            if(node->right!=nullptr){
                ans.push_back(node->right);
            }
            return true;
        }
        return false;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        std::sort(to_delete.begin(),to_delete.end());
        if(!dfs(root,to_delete)){
            ans.push_back(root);
        }
        return ans;
    }
};