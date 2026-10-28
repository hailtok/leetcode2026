// Problem 55: Jump Game
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxstep=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i+nums[i]>maxstep){
                maxstep=i+nums[i];
            }
            if(i>=maxstep){
                return false;
            }
        }
        if(maxstep>=nums.size()-1){
            return true;
        }
        else{
            return false;
        }
    }
};