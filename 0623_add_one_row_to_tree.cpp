// Problem 623: Add One Row to Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/add-one-row-to-tree/

class Solution {
public:
    int goal_depth=0;
    void dfs(TreeNode* node,int depth,int &val){
        if(node==nullptr){
            return;
        }
        if(depth+1==goal_depth){
            TreeNode* new_left=new TreeNode(val);
            TreeNode* new_right=new TreeNode(val);
            new_left->left=node->left;
            node->left=new_left;
            new_right->right=node->right;
            node->right=new_right;
            return;
        }
        dfs(node->left,depth+1,val);
        dfs(node->right,depth+1,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* new_root=new TreeNode(val);
            new_root->left=root;
            return new_root;
        }
        else{
            goal_depth=depth;
            dfs(root,1,val);
        }
        return root;
    }
};