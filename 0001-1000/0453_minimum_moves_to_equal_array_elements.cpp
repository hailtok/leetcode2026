// Problem 453: Minimum Moves to Equal Array Elements
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0,min_number=INT_MAX;
        for(int i=0;i<nums.size();i++){
            min_number=min(min_number,nums[i]);
            sum+=nums[i];
        }
        return sum-nums.size()*min_number;
    }
};