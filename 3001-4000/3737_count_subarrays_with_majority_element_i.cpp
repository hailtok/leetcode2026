// Problem 3737: Count Subarrays With Majority Element I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-subarrays-with-majority-element-i/

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int>freq(nums.size()+1,0);
        for(int i=0;i<nums.size();++i){
            freq[i+1]=freq[i];
            if(nums[i]==target){
                ++freq[i+1];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();++i){
            for(int j=i;j<nums.size();++j){
                if(j-i+1<(freq[j+1]-freq[i])*2){
                    ++ans;
                }
            }
        }
        return ans;
    }
};