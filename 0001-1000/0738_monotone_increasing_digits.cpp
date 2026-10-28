// Problem 738: Monotone Increasing Digits
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/monotone-increasing-digits/

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int>nums;
        while(n>0){
            nums.push_back(n%10);
            n/=10;
        }
        for(int i=0;i<(int)nums.size()-1;++i){
            if(nums[i]<nums[i+1]){
                ++i;
                while(i<nums.size()-1&&nums[i]<=nums[i+1]){
                    ++i;
                }
                --nums[i];
                for(int j=i-1;j>=0;--j){
                    nums[j]=9;
                }
            }
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;--i){
            ans*=10;
            ans+=nums[i];
        }
        return ans;
    }
};