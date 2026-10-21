// Problem 1261: Find Elements in a Contaminated Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements {
public:
    unordered_map<int,int>umap;
    void dfs(TreeNode* node,int value){
        if(node==nullptr){
            return;
        }
        node->val=value;
        ++umap[value];
        dfs(node->left,value*2+1);
        dfs(node->right,value*2+2);
    }
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    bool find(int target) {
        if(umap[target]!=0){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */