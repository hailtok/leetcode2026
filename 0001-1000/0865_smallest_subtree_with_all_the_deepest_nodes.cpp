// Problem 865: Smallest Subtree with all the Deepest Nodes
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

class Solution {
public:
    int max_depth=0;
    TreeNode* ans=nullptr;
    int dfs(TreeNode* node,int depth){
        if(node==nullptr){
            return depth;
        }
        int left=dfs(node->left,depth+1),right=dfs(node->right,depth+1);
        if(left==right){
            if(left>=max_depth){
                ans=node;
                max_depth=left;
            }
        }
        return std::max(left,right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};