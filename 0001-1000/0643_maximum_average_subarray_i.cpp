// Problem 643: Maximum Average Subarray I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=DBL_MIN,total=0;
        for(int i=0;i<k;++i){
            total+=nums[i];
        }
        ans=total/k;
        for(int i=k;i<nums.size();++i){
            total=total-nums[i-k]+nums[i];
            ans=std::max(ans,total/k);
        }
        return ans;
    }
};