// Problem 1509: Minimum Difference Between Largest and Smallest Value in Three Moves
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int output=nums[nums.size()-1]-nums[3];
        output=min(nums[nums.size()-2]-nums[2],output);
        output=min(nums[nums.size()-3]-nums[1],output);
        output=min(nums[nums.size()-4]-nums[0],output);
        return output;
    }
};