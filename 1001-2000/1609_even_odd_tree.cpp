// Problem 1609: Even Odd Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/even-odd-tree/

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
    bool check=true;
    vector<int>nums;
    void dfs(TreeNode* node,int depth){
        if(node==NULL){
            return;
        }
        if(depth+1>nums.size()){
            if(depth%2){
                if(node->val%2!=0){
                    check=false;
                }
            }
            else{
                if(node->val%2==0){
                    check=false;
                }                
            }
            nums.push_back(node->val);
        }
        else{
            if(depth%2){
                if(nums[depth]<=node->val||node->val%2!=0){
                    check=false;
                }
                nums[depth]=node->val;
            }
            else{
                if(nums[depth]>=node->val||node->val%2==0){
                    check=false;
                }
                nums[depth]=node->val;
            }
        }
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        dfs(root,0);
        return check;
    }
};