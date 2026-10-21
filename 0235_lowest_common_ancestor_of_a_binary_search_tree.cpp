// Problem 235: Lowest Common Ancestor of a Binary Search Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
public:
    int target1,target2;
    TreeNode* answer=nullptr;
    int dfs(TreeNode* node){
        if(!node){
            return 0;
        }
        int left=dfs(node->left),right=dfs(node->right);
        if(left+right==2&&answer==nullptr){
            answer=node;
        }
        if(node->val==target1||node->val==target2){
            if(left+right==1&&answer==nullptr){
                answer=node;
            }
            return left+right+1;
        }
        return left+right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        target1=p->val;
        target2=q->val;
        dfs(root);
        return answer;
    }
};