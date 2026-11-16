// Problem 2364: Count Number of Bad Pairs
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-number-of-bad-pairs/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>freq;
        long long good=0;
        for(int i=0;i<nums.size();++i){
            int key=nums[i]-i;
            good+=freq[key];
            ++freq[key];
        }
        return nums.size()*(nums.size()-1)/2-good;
    }
};