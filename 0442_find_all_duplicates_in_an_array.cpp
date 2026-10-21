// Problem 442: Find All Duplicates in an Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        nums.push_back(0);
        vector<int>output;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    if(nums[i]!=0){
                        output.push_back(nums[i]);
                    }
                    nums[i]=0;
                    break;
                }
                swap(nums[i],nums[nums[i]]);
            }
        }
        return output;
    }
};