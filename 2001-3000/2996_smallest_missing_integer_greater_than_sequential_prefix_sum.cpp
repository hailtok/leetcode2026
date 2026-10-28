// Problem 2996: Smallest Missing Integer Greater Than Sequential Prefix Sum
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size()&&nums[i-1]+1==nums[i];++i){
            sum+=nums[i];
        }
        std::sort(nums.begin(),nums.end());
        int index=lower_bound(nums.begin(),nums.end(),sum)-nums.begin();
        while(index<nums.size()&&sum==nums[index]){
            while(index<nums.size()&&sum==nums[index]){
                ++index;
            }
            ++sum;
        }
        return sum;
    }
};