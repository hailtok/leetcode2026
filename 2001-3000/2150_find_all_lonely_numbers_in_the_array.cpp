// Problem 2150: Find All Lonely Numbers in the Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>output;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1&&!mp.count(nums[i]+1)&&!mp.count(nums[i]-1)){
                output.push_back(nums[i]);
            }
        }
        return output;
    }
};