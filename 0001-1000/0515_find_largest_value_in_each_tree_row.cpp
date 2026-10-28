// Problem 515: Find Largest Value in Each Tree Row
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int>output;
    void recursion(TreeNode* node,int depth){
        if(node==nullptr){
            return;
        }
        if(output.size()<=depth){
            output.resize(depth+1,INT_MIN);
        }
        output[depth]=max(output[depth],node->val);
        recursion(node->right,depth+1);
        recursion(node->left,depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        recursion(root,0);
        return output;
    }
};