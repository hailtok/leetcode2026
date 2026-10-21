// Problem 823: Binary Trees With Factors
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        std::sort(arr.begin(),arr.end());
        vector<long long>dp(arr.size(),1);
        const int mod=1e9+7;
        for(int i=1;i<arr.size();++i){
            int j=0;
            while((long long)arr[j]*arr[j]<arr[i]){
                if(arr[i]%arr[j]==0){
                    int factor=arr[i]/arr[j];
                    if(std::binary_search(arr.begin(),arr.end(),factor)){
                        int index=lower_bound(arr.begin(),arr.end(),factor)-arr.begin();
                        dp[i]=(dp[i]+2*dp[j]*dp[index])%mod;
                    }
                }
                ++j;
            }
            if((long long)arr[j]*arr[j]==arr[i]){
                dp[i]=(dp[i]+dp[j]*dp[j])%mod;
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();++i){
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};