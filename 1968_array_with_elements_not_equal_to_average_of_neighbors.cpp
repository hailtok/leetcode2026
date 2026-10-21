// Problem 1968: Array With Elements Not Equal to Average of Neighbors
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ranges::sort(nums.begin(),nums.end());
        vector<int>answer(nums.size());
        for(int i=0,left=0,right=nums.size()-1;i<nums.size();++i){
            if(i%2==0){
                answer[i]=nums[left];
                ++left;
            }
            else{
                answer[i]=nums[right];
                --right;
            }
        }
        return answer;
    }
};