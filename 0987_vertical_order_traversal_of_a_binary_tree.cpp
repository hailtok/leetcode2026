// Problem 987: Vertical Order Traversal of a Binary Tree
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    void dfs(TreeNode* node,int col,int row,map<int,map<int,multiset<int>>>&nodes){
        if(node==nullptr){
            return;
        }
        nodes[col][row].insert(node->val);
        dfs(node->left,col-1,row+1,nodes);
        dfs(node->right,col+1,row+1,nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>nodes;
        dfs(root,0,0,nodes);
        for(auto column:nodes){
            vector<int>col;
            for(auto rows:column.second){
                col.insert(col.end(),rows.second.begin(),rows.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};