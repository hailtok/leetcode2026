// Problem 137: Single Number II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> all;
	for (int i = 0, temp = nums[i];i<nums.size();i++) {
		all[nums[i]]++;
	}
	for (unordered_map<int, int>::iterator i=all.begin(); i != all.end(); i++) {
		if (i->second==1) {
			return i->first;
		}
	}
        return 0;
    }
};