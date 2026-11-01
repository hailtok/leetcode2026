// Problem 2535: Difference Between Element Sum and Digit Sum of an Array
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i){
            ans+=nums[i];
            while(nums[i]>0){
                ans-=nums[i]%10;
                nums[i]/=10;
            }
        }
        return ans;
    }
};