// Problem 15: 3Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>output;
        for(int i=0;i<nums.size()-2;i++){
            int begin=i+1,end=nums.size()-1;
            if(i!=0&&nums[i-1]==nums[i]){
                continue;
            }
            while(begin<end){
                if(nums[i]+nums[begin]+nums[end]>0){
                    end--;
                }
                else if(nums[i]+nums[begin]+nums[end]<0){
                    begin++;
                }
                else{
                    output.push_back({nums[i],nums[begin],nums[end]});
                    begin++;
                    while(begin<nums.size()&&nums[begin]==nums[begin-1]){
                        begin++;
                    }
                }
            }
        }
        return output;
    }
};