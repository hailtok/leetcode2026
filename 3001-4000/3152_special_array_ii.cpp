// Problem 3152: Special Array II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/special-array-ii/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>answer(queries.size(),true);
        vector<int>dp(1,0);
        for(int i=1,j=0;i<nums.size();++i){
            if(nums[i]%2==nums[i-1]%2){
                j++;
            }
            dp.push_back(j);
        }
        for(int i=0;i<queries.size();++i){
            answer[i]=(dp[queries[i][0]]==dp[queries[i][1]]);
        }
        return answer;
    }
};