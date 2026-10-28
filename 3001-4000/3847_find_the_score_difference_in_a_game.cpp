// Problem 3847: Find the Score Difference in a Game
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-score-difference-in-a-game/

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int ans=0;
        bool turn=true;
        for(int i=0;i<nums.size();++i){
            if(nums[i]&1==1){
                turn=!turn;
            }
            if(i%6==5){
                turn=!turn;
            }
            if(turn){
                ans+=nums[i];
            }
            else{
                ans-=nums[i];
            }
        } 
        return ans;
    }
};