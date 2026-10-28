// Problem 2385: Amount of Time for Binary Tree to Be Infected
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

pair <int, int> DFS(TreeNode *nowNode, int start) {
    pair <int, int> lefts = { 0, -1 }, rights = { 0, -1 };
    if(nowNode->left) 
        lefts = DFS(nowNode->left, start);
    if(nowNode->right) 
        rights = DFS(nowNode->right, start);
    if(nowNode->val == start) 
        return { 0, max(lefts.first, rights.first) };
    if (lefts.second != -1) 
        return { lefts.first + 1, max(lefts.second, lefts.first + rights.first + 1) };
    if (rights.second != -1) 
        return { rights.first + 1, max(rights.second, lefts.first + rights.first + 1) };
    return { max(lefts.first, rights.first) + 1, -1 };
}

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        return DFS(root, start).second;
    }
};