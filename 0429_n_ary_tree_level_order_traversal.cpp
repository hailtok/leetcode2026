// Problem 429: N-ary Tree Level Order Traversal
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> answer;
    void dfs(Node* node,int depth){
        if(node==nullptr){
            return ;
        }
        if(answer.size()<=depth){
            answer.push_back(vector<int>{node->val});
        }
        else{
            answer[depth].push_back(node->val);
        }
        for(int i=0;i<node->children.size();i++){
            dfs(node->children[i],depth+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root,0);
        return answer;
    }
};