// Problem 128: Longest Consecutive Sequence
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uset;
        for(int i=0;i<nums.size();i++){
            uset.insert(nums[i]);
        }
        int output=0;
        for(int i=0;i<nums.size();i++){
            if(uset.find(nums[i]-1)==uset.end()){
                int current_number=nums[i],current_sequence=1;
                while(uset.find(current_number+1)!=uset.end()){
                    current_number++;
                    current_sequence++;
                }
                output=max(output,current_sequence);
            }
        }
        return output;
    }
};