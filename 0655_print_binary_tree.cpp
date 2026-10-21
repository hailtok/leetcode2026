// Problem 655: Print Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/print-binary-tree/

class Solution {
public:
    vector<vector<string>>answer;
    int max_depth(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        return std::max(max_depth(node->left),max_depth(node->right))+1;
    }
    void dfs(TreeNode* node,int depth,int left,int right){
        if(node==nullptr){
            return;
        }
        int index=left+(right-left)/2;
        answer[depth][index]=to_string(node->val);
        dfs(node->left,depth+1,left,index);
        dfs(node->right,depth+1,index+1,right);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int depth=max_depth(root),width=std::pow(2,depth)-1;
        answer=vector<vector<string>>(depth,vector<string>(width,""));
        dfs(root,0,0,width);
        return answer;
    }
};