// Problem 1315: Sum of Nodes with Even-Valued Grandparent
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int output=0;
    void add(TreeNode* node){
        if(node==nullptr){
            return;
        }
        if(node->right){
            output+=node->right->val;
        }
        if(node->left){
            output+=node->left->val;
        }
    }
    void add_number(TreeNode* node){
        if(node==nullptr){
            return;
        }
        else{
            output+=node->val;
        }
    }
    void recursion(TreeNode* node){
        if(node==nullptr){
            return;
        }
        if(node->val%2==0){
            add(node->right);
            add(node->left);
        }
        recursion(node->right);
        recursion(node->left);
    }
    int sumEvenGrandparent(TreeNode* root) {
        recursion(root);
        return output;
    }
};