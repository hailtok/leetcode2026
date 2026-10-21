// Problem 230: Kth Smallest Element in a BST
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    int answer;
    int dfs(TreeNode* node,int num){
        if(node==nullptr){
            return 0;
        }
        int left=dfs(node->left,num),right=dfs(node->right,num-left-1);
        if(num-left==1){
            answer=node->val;
        }
        return left+right+1;
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return answer;
    }
};