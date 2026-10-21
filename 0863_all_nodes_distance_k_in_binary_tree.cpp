// Problem 863: All Nodes Distance K in Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    vector<int>ans;
    int dis;
    void dfs(TreeNode* node,int k){
        if(node==nullptr){
            return;
        }
        cout<<"node->val:"<<node->val<<endl;
        cout<<"k:"<<k<<endl;
        if(k==0){
            ans.push_back(node->val);
        }
        dfs(node->left,k-1);
        dfs(node->right,k-1);
    }
    int find_target(TreeNode* node,TreeNode* target){
        if(node==nullptr){
            return -1;
        }
        if(node->val==target->val){
            if(dis==0){
                ans.push_back(node->val);
            }
            dfs(node->left,dis-1);
            dfs(node->right,dis-1);
            return 0;
        }
        int left=find_target(node->left,target),right=find_target(node->right,target);
        if(left!=-1){
            if(dis-left-1==0){
                ans.push_back(node->val);
            }
            dfs(node->right,dis-left-2);
            return std::max(left,right)+1;
        }
        if(right!=-1){
            if(dis-right-1==0){
                ans.push_back(node->val);
            }
            dfs(node->left,dis-right-2);
            return std::max(left,right)+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dis=k;
        find_target(root,target);
        return ans;
    }
};