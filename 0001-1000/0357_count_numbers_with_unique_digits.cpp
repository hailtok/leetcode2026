// Problem 357: Count Numbers with Unique Digits
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            unsigned output=9;
            for(int j=1;j<i;j++){
                output*=(9-j+1);
            }
            dp[i]=output+dp[i-1];
        }
        return dp[n];
    }
};