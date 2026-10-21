// Problem 1458: Max Dot Product of Two Subsequences
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-100000000));
        dp[0][0]=nums1[0]*nums2[0];
        for(int i=1;i<dp.size();++i){
            dp[i][0]=std::max(dp[i-1][0],nums1[i]*nums2[0]);
        }
        for(int i=1;i<dp[0].size();++i){
            dp[0][i]=std::max(dp[0][i-1],nums1[0]*nums2[i]);
        }
        for(int i=1;i<nums1.size();++i){
            for(int j=1;j<nums2.size();++j){
                dp[i][j]=std::max({nums1[i]*nums2[j]+std::max(dp[i-1][j-1],0),dp[i][j],dp[i][j-1],dp[i-1][j]});
            }
        }
        return dp[nums1.size()-1][nums2.size()-1];
    }
};