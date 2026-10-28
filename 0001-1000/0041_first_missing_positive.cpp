// Problem 41: First Missing Positive
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                mp[nums[i]]++;
            }
        }
        for(int i=0;i<nums.size()+1;i++){
            if(mp.find(i+1)==mp.end()){
                return i+1;
            }
        }
        return 0;
    }
};