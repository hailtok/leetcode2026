// Problem 3736: Minimum Moves to Equal Array Elements III
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0,Max=0;
        for(int i=0;i<nums.size();++i){
            if(Max>=nums[i]){
                ans+=Max-nums[i];
            }
            else{
                ans+=(i*(nums[i]-Max));
                Max=nums[i];
            }
        }
        return ans;
    }
};