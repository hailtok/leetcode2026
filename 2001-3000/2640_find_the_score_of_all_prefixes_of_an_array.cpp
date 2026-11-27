// Problem 2640: Find the Score of All Prefixes of an Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long>ans(nums.size(),0);
        int max=nums[0];
        long long sum=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>max){
                max=nums[i];
            }
            nums[i]+=max;
            sum+=(long long)nums[i];
            ans[i]=sum;
        }
        return ans;
    }
};