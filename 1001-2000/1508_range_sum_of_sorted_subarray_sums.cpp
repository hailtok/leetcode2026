// Problem 1508: Range Sum of Sorted Subarray Sums
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>prefix(n+1,0);
        for(int i=0,sum=0;i<n;++i){
            prefix[i+1]=prefix[i]+nums[i];
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<=n;++i){
            for(int j=0;j<i;++j){
                pq.push(prefix[i]-prefix[j]);
            }
        }
        static constexpr int mod=1e9+7;
        int ans=0;
        for(int i=1;i<=right;++i){
            int val=pq.top();
            pq.pop();
            if(i>=left){
                ans=(ans+val)%mod;
            }
        }
        return ans;
    }
};