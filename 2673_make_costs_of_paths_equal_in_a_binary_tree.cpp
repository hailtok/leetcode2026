// Problem 2673: Make Costs of Paths Equal in a Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/

class Solution {
public:
    int ans=0;
    int dfs(int root, vector<int>& cost, int& n){
        if(root >n){
            return 0;
        }
        int left=dfs(root*2,cost,n);
        int right=dfs(root*2+1,cost,n);
        ans+=abs(left-right);
        return cost[root-1]+max(left,right);
    }
    
    int minIncrements(int n, vector<int>& cost) {
        dfs(1,cost,n);
        return ans;
    }
};