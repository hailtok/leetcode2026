// Problem 1367: Linked List in Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/linked-list-in-binary-tree/

class Solution {
public:
    bool dfs(TreeNode* node,ListNode* list){
        if(!node){
            return false;
        }
        if(list->val!=node->val){
            return false;
        }
        if(list->next==nullptr){
            return true;
        }
        bool left=false,right=false;
        left=dfs(node->left,list->next);
        right=dfs(node->right,list->next);
        return left||right;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }
        if(root->val==head->val){
            if(dfs(root,head)){
                return true;
            }
        }
        return isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};