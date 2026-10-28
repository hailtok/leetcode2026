// Problem 2679: Sum in a Matrix
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-in-a-matrix/

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int answer=0;
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(),nums[i].end());
        }
        for(int i=0;i<nums[0].size();i++){
            int temp=0;
            for(int j=0;j<nums.size();j++){
                temp=max(temp,nums[j][i]);
            }
            answer+=temp;
        }
        return answer;
    }
};