// Problem 100: Same Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/same-tree/

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
    bool dfs(TreeNode* p, TreeNode* q){
        if(p==NULL){
            if(q==NULL){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(q==NULL){
                return false;
            }
        }
        bool check=true;
        if(p->val!=q->val){
            check= false;
        }
        else{
            check= true;
        }
        check=dfs(p->right,q->right)&&check;
        check=dfs(p->left,q->left)&&check;
        return check;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};