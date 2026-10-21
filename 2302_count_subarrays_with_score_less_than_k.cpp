// Problem 2302: Count Subarrays With Score Less Than K
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left=0;
        long long sum=0,ans=0;
        for(int right=0;right<nums.size();++right){
            sum+=nums[right];
            while(sum*(right-left+1)>=k&&left<=right){
                sum-=nums[left];
                ++left;
            }
            ans+=right-left+1;
        }
        return ans;
    }
};