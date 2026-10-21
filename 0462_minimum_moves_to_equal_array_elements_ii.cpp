// Problem 462: Minimum Moves to Equal Array Elements II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int answer=0;
        for(int i=0,temp=nums[nums.size()/2];i<nums.size();i++){
            answer+=abs(nums[i]-temp);
        }
        return answer;
    }
};