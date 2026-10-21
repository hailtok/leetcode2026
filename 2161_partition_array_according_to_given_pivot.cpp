// Problem 2161: Partition Array According to Given Pivot
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/partition-array-according-to-given-pivot/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less,same,greater;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                greater.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                same.push_back(nums[i]);
            }
            else{
                less.push_back(nums[i]);
            }
        }
        less.insert(less.end(),same.begin(),same.end());
        less.insert(less.end(),greater.begin(),greater.end());
        return less;
    }
};