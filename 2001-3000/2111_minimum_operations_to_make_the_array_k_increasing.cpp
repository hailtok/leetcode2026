// Problem 2111: Minimum Operations to Make the Array K-Increasing
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans=0;
        vector<int>dp;
        for(int i=0;i<k;++i){
            dp.push_back(arr[i]);
            int count=1;
            for(int j=i+k;j<arr.size();j+=k,++count){
                int index=upper_bound(dp.begin(),dp.end(),arr[j])-dp.begin();
                if(index>=dp.size()){
                    dp.push_back(arr[j]);
                }
                else{
                    dp[index]=arr[j];
                }
            }
            ans+=count-dp.size();
            dp.clear();
        }
        return ans;
    }
};