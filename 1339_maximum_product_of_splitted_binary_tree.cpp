// Problem 1339: Maximum Product of Splitted Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

class Solution {
public:
    int ans=INT_MIN,total=0,mod=1e9+7;
    long long prod_max=INT_MIN;
    int count(TreeNode* node){
        if(!node){
            return 0;
        }
        int left=count(node->left),right=count(node->right);
        node->val+=left+right;
        return node->val;
    }
    void find(TreeNode* node,int target){
        if(!node){
            return;
        }
        long long temp=(long long)node->val*((long long)total-node->val);
        if(temp>prod_max){
            prod_max=temp;
            ans=temp%mod;
        }
        find(node->left,target);
        find(node->right,target);
    }
    int maxProduct(TreeNode* root) {
        total=count(root);  
        find(root,total);
        return ans;
    }
};