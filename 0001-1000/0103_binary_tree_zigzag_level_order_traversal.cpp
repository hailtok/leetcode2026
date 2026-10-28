// Problem 103: Binary Tree Zigzag Level Order Traversal
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>>answer;
    void dfs(TreeNode* node,int depth){
        if(!node){
            return;
        }
        if(answer.size()<=depth){
            answer.push_back(vector<int>());
        }
        answer[depth].push_back(node->val);
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root,0);
        for(int i=1;i<answer.size();i+=2){
            std::reverse(answer[i].begin(),answer[i].end());
        }
        return answer;
    }
};