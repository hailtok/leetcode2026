// Problem 2740: Find the Value of the Partition
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-value-of-the-partition/

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int answer=INT_MAX;
        for(int i=0;i<nums.size()-1;++i){
            answer=std::min(std::abs(nums[i+1]-nums[i]),answer);
        }
        return answer;
    }
};