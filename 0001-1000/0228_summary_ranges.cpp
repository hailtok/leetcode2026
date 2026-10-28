// Problem 228: Summary Ranges
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>output;
        int index=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]-1){
                if(nums[index]==nums[i-1]){
                    output.push_back(to_string(nums[i-1]));
                }
                else{
                    output.push_back(to_string(nums[index])+"->"+to_string(nums[i-1]));
                }
                index=i;
            }
        }
        if(index!=nums.size()){
            if(index==nums.size()-1){
                output.push_back(to_string(nums[nums.size()-1]));
            }
            else{
                output.push_back(to_string(nums[index])+"->"+to_string(nums[nums.size()-1]));
            }
        }
        return output;
    }
};