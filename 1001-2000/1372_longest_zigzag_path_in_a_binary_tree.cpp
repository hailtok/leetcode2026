// Problem 1372: Longest ZigZag Path in a Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

class Solution {
public:
    int path=0;
    void dfs(TreeNode* node,bool last_move,int value){
        if(node==nullptr){
            return;
        }
        path=std::max(path,value);
        if(last_move){
            dfs(node->left,true,1);
            dfs(node->right,false,value+1);
        }
        else{
            dfs(node->left,true,value+1);
            dfs(node->right,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        return path;
    }
};