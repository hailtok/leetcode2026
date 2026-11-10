// Problem 3754: Concatenate Non-Zero Digits and Multiply by Sum I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0,total=0;
        vector<int>nums;
        while(n>0){
            if(n%10!=0){
                nums.push_back(n%10);
            }
            total+=n%10;
            n/=10;
        }
        for(int i=nums.size()-1;i>=0;--i){
            ans*=10;
            ans+=nums[i];
        }
        return ans*total;
    }
};