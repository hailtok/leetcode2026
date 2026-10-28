// Problem 99: Recover Binary Search Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode* root) {
        vector<int>numbers;
        inorder(root,numbers);
        sort(numbers.begin(),numbers.end());
        vector<int>::iterator it = numbers.begin();
        write_in(root,it);
    }
    void write_in(TreeNode* node,vector<int>::iterator& it){
        if(!node){
            return ;
        }
        write_in(node->left,it);
        node->val=*it;
        it++;
        write_in(node->right,it);
    }
    void inorder(TreeNode* node,vector<int>& array){
        if(!node){
            return ;
        }
        inorder(node->left,array);
        array.push_back(node->val);
        inorder(node->right,array);
    }
};