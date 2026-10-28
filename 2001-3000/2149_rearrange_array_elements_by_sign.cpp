// Problem 2149: Rearrange Array Elements by Sign
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>output(nums.size());
        queue<int>positive,negative;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                positive.push(nums[i]);
            }
            else{
                negative.push(nums[i]);
            }
        }
        bool turn=true;
        for(int i=0;i<nums.size();i++){
            if(turn){
                output[i]=positive.front();
                positive.pop();
                turn=false;
            }
            else{
                output[i]=negative.front();
                negative.pop();
                turn=true;
            }
        }
        return output;
    }
};