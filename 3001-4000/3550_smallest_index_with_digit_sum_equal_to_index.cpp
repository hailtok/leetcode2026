// Problem 3550: Smallest Index With Digit Sum Equal to Index
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=0;
        while(ans<nums.size()){
            int temp=0;
            while(nums[ans]>0){
                temp+=nums[ans]%10;
                nums[ans]/=10;
            }
            if(ans==temp){
                break;
            }
            ++ans;
        }
        return ans==nums.size()?-1:ans;
    }
};