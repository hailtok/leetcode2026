// Problem 2588: Count the Number of Beautiful Subarrays
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int>umap{{0,1}};
        long long ans=0,pre=0;
        for(int i=0;i<nums.size();++i){
            pre^=nums[i];
            ans+=umap[pre];
            ++umap[pre];
        }
        return ans;
    }
};