// Problem 560: Subarray Sum Equals K
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(prefix[i]==k){
                ++ans;
            }
            if(mp.find(prefix[i]-k)!=mp.end()){
                ans+=mp[prefix[i]-k];
            }
            ++mp[prefix[i]];
        }
        return ans;
    }
};