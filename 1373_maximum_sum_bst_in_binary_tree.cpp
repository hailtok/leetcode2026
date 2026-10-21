// Problem 1373: Maximum Sum BST in Binary Tree
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

class Solution {
public:
    int ans=0;
    vector<int>dfs(TreeNode* node){
        if(node==nullptr){
            return {true,INT_MIN,INT_MAX,0};
        }
        vector<int>left=dfs(node->left),right=dfs(node->right);
        if(left[2]==INT_MAX){
            left[2]=INT_MIN;
        }
        if(right[1]==INT_MIN){
            right[1]=INT_MAX;
        }
        if(left[0]&&right[0]&&node->val>left[2]&&right[1]>node->val){
            ans=std::max(ans,node->val+left[3]+right[3]);
            if(left[1]==INT_MIN){
                left[1]=node->val;
            }
            if(right[2]==INT_MAX){
                right[2]=node->val;
            }
            return {true,left[1],right[2],node->val+left[3]+right[3]};
        }
        return {false,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};