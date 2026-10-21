// Problem 236: Lowest Common Ancestor of a Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int num1,num2;
    TreeNode* answer;
    int dfs(TreeNode* node){
        int check=0;
        if(node==NULL){
            return 0;
        }
        if(num1==node->val||num2==node->val){
            check++;
        }
        check+=dfs(node->right);
        check+=dfs(node->left);
        if(check==2){
            answer=node;
            return check+1;
        }
        return check;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        num1=p->val;
        num2=q->val;
        dfs(root);
        return answer;
    }
};