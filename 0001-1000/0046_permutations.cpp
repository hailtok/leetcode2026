// Problem 46: Permutations
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>output;
        int total_time=1;
        for(int i=0;i<nums.size();i++){
           total_time*=(i+1); 
        }
        for(int i=0;i<total_time;i++){
            nextPermutation(nums);
            output.push_back(nums);
        }
        return output;
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()>=2){
            int i=nums.size()-1;
            while(i>0){
                if(nums[i]>nums[i-1]){
                    int j=nums.size()-1;
                    while(nums[i-1]>=nums[j]){
                        j--;
                    }
                    swap(nums[i-1],nums[j]);
                    reverse(nums.begin()+i,nums.end());
                    break;
                }
                i--;
            }
        if(i==0){
            reverse(nums.begin(),nums.end());
            }
        }
    }
};