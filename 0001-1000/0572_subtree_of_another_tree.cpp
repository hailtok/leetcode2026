// Problem 572: Subtree of Another Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:
    bool ans=false;
    void dfs(TreeNode *node,TreeNode *target){
        if(node==nullptr){
            return;
        }
        if(node->val==target->val){
            TreeNode *n=node,*t=target;
            if(check(n,t)){
                ans=true;
            }
        }
        dfs(node->left,target);
        dfs(node->right,target);
    }
    bool check(TreeNode *node,TreeNode * target){
        if(node==nullptr){
            if(target==nullptr){
                return true;
            }
            return false;
        }
        else{
            if(target==nullptr){
                return false;
            }
        }
        if(node->val==target->val){
            return check(node->left,target->left)&&check(node->right,target->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,subRoot);
        return ans;
    }
};