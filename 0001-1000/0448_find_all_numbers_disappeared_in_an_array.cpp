// Problem 448: Find All Numbers Disappeared in an Array
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>arr(nums.size(),0);
        for(int i=0;i<nums.size();++i){
            ++arr[nums[i]-1];
        }
        vector<int>ans;
        for(int i=0;i<arr.size();++i){
            if(arr[i]==0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};