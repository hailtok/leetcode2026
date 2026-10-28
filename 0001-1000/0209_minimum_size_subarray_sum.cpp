// Problem 209: Minimum Size Subarray Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(std::accumulate(nums.begin(),nums.end(),0)<target){
            return 0;
        }
        int left=0,right=0,sum=0,ans=INT_MAX;
        while(true){
            if(sum<target){
                if(right==nums.size()){
                    break;
                }
                sum+=nums[right];
                ++right;
            }
            else{
                ans=std::min(ans,right-left);
                sum-=nums[left];
                ++left;
            }
        }
        return ans;
    }
};