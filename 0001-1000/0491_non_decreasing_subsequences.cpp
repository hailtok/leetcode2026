// Problem 491: Non-decreasing Subsequences
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/non-decreasing-subsequences/

class Solution {
public:
    void recursion(vector<int>&nums,vector<int>& arr,int index,set<vector<int>>&ans){
        if(index>=nums.size()){
            if(arr.size()>=2){
                ans.insert(arr);
            }   
            return;
        }
        if(arr.size()==0||arr.back()<=nums[index]){
            arr.push_back(nums[index]);
            recursion(nums,arr,index+1,ans);
            arr.pop_back();
        }
        recursion(nums,arr,index+1,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        recursion(nums,temp,0,ans);
        return vector(ans.begin(),ans.end());
    }
};