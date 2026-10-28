// Problem 117: Populating Next Right Pointers in Each Node II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

class Solution {
public:
    vector<Node*>nodes;
    void dfs(Node* node,int depth){
        if(node==nullptr){
            return;
        }
        if(nodes.size()<=depth){
            nodes.push_back(node);
        }
        else{
            nodes[depth]->next=node;
            nodes[depth]=node;
        }
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
    Node* connect(Node* root) {
        dfs(root,0);
        for(int i=0;i<nodes.size();++i){
            cout<<nodes[i]->val<<endl;
            nodes[i]->next=nullptr;
        }
        return root;
    }
};