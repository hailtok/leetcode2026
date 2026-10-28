// Problem 2221: Find Triangular Sum of an Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-triangular-sum-of-an-array/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>temp=nums;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<i;j++){
                temp[j]=(temp[j]+temp[j+1])%10;
            }
        }
        return temp[0];
    }
};