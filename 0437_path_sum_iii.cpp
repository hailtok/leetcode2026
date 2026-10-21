// Problem 437: Path Sum III
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/path-sum-iii/

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
    int answer=0,sum;
    void dfs(TreeNode* node,vector<long long>totals){
        if(node==NULL){
            return;
        }
        for(int i=totals.size()-1;i>=0;i--){
            totals[i]+=node->val;
        }
        totals.push_back(node->val);
        for(int i=0;i<totals.size();i++){
            if(sum==totals[i]){
                answer++;
            }
        }
        dfs(node->right,totals);
        dfs(node->left,totals);
    }
    int pathSum(TreeNode* root, int targetSum) {
        sum=targetSum;
        if(root!=NULL&&targetSum==root->val){
            answer++;
        }
        if(root!=NULL){
            dfs(root->right,{root->val});
            dfs(root->left,{root->val});
        }
        return answer;
    }
};