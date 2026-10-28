// Problem 229: Majority Element II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,number=nums[0];
        vector<int>output;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=number){
                if(count>nums.size()/3){
                    output.push_back(number);
                }
                count=1;
                number=nums[i];
            }
            else{
                count++;
            }
        }
        if(count>nums.size()/3){
            output.push_back(number);
        }
        return output;
    }
};