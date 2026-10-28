// Problem 2401: Longest Nice Subarray
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-nice-subarray/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int answer=1,temp=nums[0],left=0;
        for(int right=1;right<nums.size();++right){
            while((temp&nums[right])!=0){
                temp^=nums[left];
                ++left;
            }
            temp|=nums[right];
            answer=std::max(answer,right-left+1);
        }
        return answer;
    }
};