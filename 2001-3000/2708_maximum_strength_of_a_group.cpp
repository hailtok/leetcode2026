// Problem 2708: Maximum Strength of a Group
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-strength-of-a-group/

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        long long ans=1;
        int count=0,last_n=INT_MIN;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                ans*=nums[i];
            }
            else if(nums[i]<0){
                ans*=nums[i];
                ++count;
                if(last_n<nums[i]){
                    last_n=nums[i];
                }
            }
        }
        if(count%2==1){
            ans/=last_n;
            --count;
        }
        if(ans==1&&count==0){
            int max=INT_MIN;
            for(int i=0;i<nums.size();++i){
                max=std::max(max,nums[i]);
            }
            return max;
        }
        return ans;
    }
};