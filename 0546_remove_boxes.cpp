// Problem 546: Remove Boxes
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/remove-boxes/

class Solution {
public:
    int recursion(vector<int>&boxes,vector<vector<vector<int>>>&dp,int left,int right,int k){
        if(left>right){
            return 0;
        }
        if(dp[left][right][k]!=0){
            return dp[left][right][k];
        }
        int left_temp=left,k_temp=k;
        while(left<right&&boxes[left]==boxes[left+1]){
            ++left;
            ++k;
        }
        int res=(k+1)*(k+1)+recursion(boxes,dp,left+1,right,0);
        for(int m=left+1;m<=right;++m){
            if(boxes[m]==boxes[left]){
                res=std::max(res,recursion(boxes,dp,left+1,m-1,0)+recursion(boxes,dp,m,right,k+1));
            }
        }
        dp[left_temp][right][k_temp]=res;
        return res;
    }
    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>>dp(boxes.size(),vector<vector<int>>(boxes.size(),vector<int>(boxes.size())));
        return recursion(boxes,dp,0,boxes.size()-1,0);
    }
};