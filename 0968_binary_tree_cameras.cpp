// Problem 968: Binary Tree Cameras
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-cameras/

class Solution {
public:
    int ans=0;
    int dfs(TreeNode* node){
        if(node==nullptr){
            return 1;
        }
        int left=dfs(node->left),right=dfs(node->right);
        if(left==0||right==0){
            ++ans;
            return 2;
        }
        else if(left==2||right==2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0){
            ++ans;
        }
        return ans;
    }
};