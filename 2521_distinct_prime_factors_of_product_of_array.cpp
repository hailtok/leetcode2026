// Problem 2521: Distinct Prime Factors of Product of Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int>prime={2,3,5,7,11,13,17,19,23,29,31,37};
        set<int>count;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<prime.size();j++){
                if(nums[i]%prime[j]==0){
                    count.insert(prime[j]);
                    while(nums[i]%prime[j]==0){
                        nums[i]/=prime[j];
                    }
                }
            }
            if(nums[i]!=1){
                count.insert(nums[i]);
            }
        }
        return count.size();
    }
};