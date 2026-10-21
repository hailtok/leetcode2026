// Problem 3718: Smallest Missing Multiple of K
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/smallest-missing-multiple-of-k/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>uset(nums.begin(),nums.end());
        int cur=k;
        while(uset.find(cur)!=uset.end()){
            cur+=k;
        }
        return cur;
    }
};