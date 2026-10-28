// Problem 3702: Longest Subsequence With Non-Zero Bitwise XOR
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool non_zero=false;
        int total=0;
        for(int i=0;i<nums.size();++i){
            total^=nums[i];
            if(nums[i]>0){
                non_zero=true;
            }
        }
        if(total>0){
            return nums.size();
        }
        if(total==0&&non_zero){
            return nums.size()-1;
        }
        return 0;
    }
};