// Problem 1161: Maximum Level Sum of a Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

class Solution {
public:
    void dfs(TreeNode* node,vector<int>&level_val,int depth){
        if(node==nullptr){
            return;
        }
        if(level_val.size()<=depth){
            level_val.push_back(node->val);
        }
        else{
            level_val[depth]+=node->val;
        }
        dfs(node->left,level_val,depth+1);
        dfs(node->right,level_val,depth+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int>level_val;
        dfs(root,level_val,0);
        int answer=0,max=INT_MIN;
        for(int i=0;i<level_val.size();++i){
            cout<<level_val[i]<<endl;
            if(max<level_val[i]){
                max=level_val[i];
                answer=i;
            }
        }
        return answer+1;
    }
};