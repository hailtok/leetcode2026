// Problem 662: Maximum Width of Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    vector<unsigned long long>left_most;
    int answer=0;
    void dfs(TreeNode* node,unsigned long long position,int depth){
        if(!node){
            return;
        }
        if(left_most.size()<=depth){
            left_most.push_back(position);
        }
        else{
            left_most[depth]=std::min(left_most[depth],position);
        }
        answer=std::max((unsigned long long)answer,position-left_most[depth]);
        dfs(node->left,position*2,depth+1);
        dfs(node->right,position*2+1,depth+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,1,0);
        return answer+1;
    }
};