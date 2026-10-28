// Problem 2913: Subarrays Distinct Element Sum of Squares I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int answer=0;
        for(int i=0;i<nums.size();++i){
            unordered_set<int>uset;
            for(int j=i;j<nums.size();++j){
                uset.insert(nums[j]);
                answer+=uset.size()*uset.size();
            }
        }
        return answer;
    }
};