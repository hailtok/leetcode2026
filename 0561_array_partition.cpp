// Problem 561: Array Partition
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/array-partition/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int answer=0;
        for(int i=0;i<nums.size();i+=2){
            answer+=min(nums[i],nums[i+1]);
        }
        return answer;
    }
};