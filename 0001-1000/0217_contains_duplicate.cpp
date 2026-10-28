// Problem 217: Contains Duplicate
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();++i){
            ++umap[nums[i]];
            if(umap[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};