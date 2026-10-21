// Problem 108: Convert Sorted Array to Binary Search Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* tree(vector<int>&nums,int left,int right){
        if(right-left<2){
            if(right-left==1){
                TreeNode* node=new TreeNode(nums[left]);
                node->right=new TreeNode(nums[right]);
                return node;
            }
            else{
                return new TreeNode(nums[left]);
            }
        }
        else{
            int pivot=left+(right-left)/2;
            TreeNode* parent=new TreeNode(nums[pivot]);
            parent->left=tree(nums,left,pivot-1);
            parent->right=tree(nums,pivot+1,right);
            return parent;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return tree(nums,0,nums.size()-1);
    }
};