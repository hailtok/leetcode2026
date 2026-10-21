// Problem 169: Majority Element
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,candidate=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate=nums[i];
            }
            if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};