// Problem 2344: Minimum Deletions to Make Array Divisible
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int factor=numsDivide[0];
        for(int i=1;i<numsDivide.size();++i){
            factor=__gcd(factor,numsDivide[i]);
        }
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()&&nums[i]<=factor;++i){
            if(factor%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};