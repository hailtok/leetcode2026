// Problem 2583: Kth Largest Sum in a Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

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
    vector<long long>sum;
    void dfs(TreeNode* node,int depth){
        if(node==nullptr){
            return;
        }
        cout<<node->val<<endl;
        if(sum.size()==depth){
            sum.push_back(node->val);
        }
        else{
            sum[depth]+=node->val;
        }
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root,0);
        std::sort(sum.begin(),sum.end());
        cout<<sum.size()<<endl;
        return k<=sum.size()?sum[sum.size()-k]:-1;
    }
};