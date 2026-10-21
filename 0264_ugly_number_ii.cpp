// Problem 264: Ugly Number II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int k1=0,k2=0,k3=0;
        for(int i=1;i<n;i++){
            int temp=min({dp[k1]*2,dp[k2]*3,dp[k3]*5});
            if(temp==dp[k1]*2){
                k1++;
            }
            if(temp==dp[k2]*3){
                k2++;
            }
            if(temp==dp[k3]*5){
                k3++;
            }
            dp[i]=temp;
        }
        return dp[n-1];
    }
};