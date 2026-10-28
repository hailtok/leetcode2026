// Problem 654: Maximum Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-binary-tree/

class Solution {
public:
    TreeNode* recursion(vector<int>&nums,int left,int right){
        if(left>=right){
            return nullptr;
        }
        int max_val=INT_MIN,index=left;
        for(int i=left;i<right;++i){
            if(max_val<nums[i]){
                max_val=nums[i];
                index=i;
            }
        }
        TreeNode* node=new TreeNode(max_val);
        node->left=recursion(nums,left,index);
        node->right=recursion(nums,index+1,right);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int max_val=INT_MIN,index=0;
        for(int i=0;i<nums.size();++i){
            if(max_val<nums[i]){
                max_val=nums[i];
                index=i;
            }
        }
        TreeNode* root=new TreeNode(max_val);
        root->left=recursion(nums,0,index);
        root->right=recursion(nums,index+1,nums.size());
        return root;
    }
};