// Problem 2553: Separate the Digits in an Array
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/separate-the-digits-in-an-array/

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;--i){
            while(nums[i]>0){
                ans.push_back(nums[i]%10);
                nums[i]/=10;
            }
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};