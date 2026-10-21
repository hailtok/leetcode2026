// Problem 993: Cousins in Binary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/cousins-in-binary-tree/

class Solution {
public:
    TreeNode* x_parent=nullptr,*y_parent=nullptr;
    int x_depth=-1,y_depth=-1,x_target,y_target;
    bool dfs(TreeNode* node,int depth){
        if(node==nullptr){
            return false;
        }
        if(node->val==x_target){
            x_depth=depth;
            return true;
        }
        else if(node->val==y_target){
            y_depth=depth;
            return true;
        }
        if(dfs(node->left,depth+1)||dfs(node->right,depth+1)){
          if(x_parent==nullptr){
            x_parent=node;
          }
          else{
            y_parent=node;
          }  
        };
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        x_target=x;
        y_target=y;
        dfs(root,0);
        if(x_depth!=y_depth||x_parent==y_parent){
            return false;
        }
        cout<<x_depth<<endl;
        return true;
    }
};