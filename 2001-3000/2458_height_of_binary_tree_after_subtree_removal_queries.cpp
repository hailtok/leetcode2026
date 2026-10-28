// Problem 2458: Height of Binary Tree After Subtree Removal Queries
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>max1;
    vector<int>max2;
    vector<int>depth;
    vector<int>heights;
    int dfs(TreeNode* node,int d){
        if(node==nullptr){
            return -1;
        }
        depth[node->val]=d;
        int h=std::max(dfs(node->left,d+1),dfs(node->right,d+1))+1;
        heights[node->val]=h;
        if(h>max1[d]){
            max2[d]=max1[d];
            max1[d]=h;
        }
        else if(h>max2[d]){
            max2[d]=h;
        }
        return h;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        max1=vector<int>(100005,-1);
        max2=vector<int>(100005,-1);
        depth=vector<int>(100005,0);
        heights=vector<int>(100005,0);
        dfs(root,0);
        vector<int>ans;
        for(int query:queries){
            int d=depth[query];
            if(heights[query]==max1[d]){
                ans.push_back(d+max2[d]);
            }
            else{
                ans.push_back(d+max1[d]);
            }
        }
        return ans;
    }
};