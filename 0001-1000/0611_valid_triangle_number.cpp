// Problem 611: Valid Triangle Number
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int output=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>1;i--){
            int begin=0,end=i-1;
            while(begin<end){
                if(nums[begin]+nums[end]>nums[i]){
                    output+=end-begin;
                    end--;
                }
                else{
                    begin++;
                }
            }
        }
        return output;
    }
};