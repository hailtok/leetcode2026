// Problem 559: Maximum Depth of N-ary Tree
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    int max_depth=0;
    void dfs(Node* node,int depth){
        if(node==nullptr){
            return;
        }
        max_depth=max(max_depth,depth);
        for(int i=0;i<node->children.size();i++){
            dfs(node->children[i],depth+1);
        }
    }
    int maxDepth(Node* root) {
        dfs(root,1);
        return max_depth;
    }
};