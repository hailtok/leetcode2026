// Problem 606: Construct String from Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/construct-string-from-binary-tree/

class Solution {
public:
    void dfs(TreeNode* node,string& answer){
        if(!node){
            return;
        }
        answer+=to_string(node->val);
        answer.push_back('(');
        dfs(node->left,answer);
        answer.push_back(')');
        answer.push_back('(');
        dfs(node->right,answer);
        if(answer.back()=='('){
            answer.pop_back();
            answer.pop_back();
            if(answer.back()=='('){
                answer.pop_back();
            }
            else{
                answer.push_back(')');
            }
        }
        else{
            answer.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        string answer="";
        dfs(root,answer);
        return answer;
    }
};