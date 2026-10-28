// Problem 1361: Validate Binary Tree Nodes
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/validate-binary-tree-nodes/

class Solution {
public:
    struct TreeNode{
        TreeNode* left;
        TreeNode* right;
        TreeNode(){
            val=0;
            left=nullptr;
            right=nullptr;
        }
        TreeNode(int _val){
            val=_val;
            left=nullptr;
            right=nullptr;
        }
        int val;
    };
    bool ans=true;
    TreeNode* dfs(vector<int>& leftChild,vector<int>& rightChild,int index,vector<bool>&visited){
        if(index==-1||!ans){
            return nullptr;
        }
        if(visited[index]){
            ans=false;
            return nullptr;
        }
        TreeNode *node=new TreeNode(index);
        visited[index]=true;
        node->left=dfs(leftChild,rightChild,leftChild[index],visited);
        node->right=dfs(leftChild,rightChild,rightChild[index],visited);
        return node;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int index=n*(n-1)/2;
        for(int i=0;i<n;++i){
            if(leftChild[i]!=-1){
                index-=leftChild[i];
            }
            if(rightChild[i]!=-1){
                index-=rightChild[i];
            }
        }
        if(index<0||index>=n){
            return false;
        }
        vector<bool>visited(n,false);
        dfs(leftChild,rightChild,index,visited);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                ans=false;
            }
        }
        return ans;
    }
};