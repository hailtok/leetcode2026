// Problem 1250: Check If It Is a Good Array
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/check-if-it-is-a-good-array/

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int check=nums[0];
        for(int i=1;i<nums.size();++i){
            check=__gcd(check,nums[i]);
        }
        return check==1;
    }
};