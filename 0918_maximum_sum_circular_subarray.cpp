// Problem 918: Maximum Sum Circular Subarray
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cur_max=nums[0],maxs=nums[0],mins=nums[0],cur_min=nums[0],sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            cur_max=max(cur_max+nums[i],nums[i]);
            maxs=max(maxs,cur_max);
            cur_min=min(cur_min+nums[i],nums[i]);
            mins=min(mins,cur_min);
        }
        if(sum==mins){
            return maxs;
        }
        else{
            return max(maxs,sum-mins);
        }
    }
};