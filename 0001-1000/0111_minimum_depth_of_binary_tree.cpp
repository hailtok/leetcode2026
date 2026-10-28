// Problem 111: Minimum Depth of Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-depth-of-binary-tree/

class Solution {
public:
    int answer=INT_MAX;
    void dfs(TreeNode* node,int depth){
        if(node==nullptr){
            return;
        }
        if(node->right==nullptr&&node->left==nullptr){
            answer=std::min(answer,depth);
        }
        dfs(node->right,depth+1);
        dfs(node->left,depth+1);
    }
    int minDepth(TreeNode* root) {
        dfs(root,1);
        if(root==nullptr){
            return 0;
        }
        return answer;
    }
};