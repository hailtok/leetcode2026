// Problem 136: Single Number
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer=0;
        for(int i=0;i<nums.size();i++){
            answer^=nums[i];
        }
        return answer;
    }
};