// Problem 18: 4Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return {};
        }
        vector<vector<int>>output;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i==0||nums[i-1]!=nums[i]){
                for(int j=i+1;j<nums.size()-2;j++){
                    if(j-1==i||nums[j-1]!=nums[j]){
                        int right=nums.size()-1,left=j+1;
                        long  current_sum=nums[i]+nums[j];
                        while(right>left){
                            if(current_sum+nums[right]+nums[left]>target){
                                right--;
                            }
                            else if(current_sum+nums[right]+nums[left]<target){
                                left++;
                            }
                            else{
                                output.push_back({nums[i],nums[j],nums[left],nums[right]});
                                right--;
                                left++;
                                while(right>=0&&nums[right+1]==nums[right]){
                                    right--;
                                }
                                while(left<nums.size()&&nums[left-1]==nums[left]){
                                    left++;
                                }
                            }
                        }
                    }
                }
            }
        }
        return output;
    }
};