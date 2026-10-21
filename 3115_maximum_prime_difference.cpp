// Problem 3115: Maximum Prime Difference
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-prime-difference/

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>primes={2,3,5,7,11,13,17,19,23,29,31,
        37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        int max=0,min=0;
        for(int i=0;i<nums.size();++i){
            if(std::binary_search(primes.begin(),primes.end(),nums[i])){
                min=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;--i){
            if(std::binary_search(primes.begin(),primes.end(),nums[i])){
                max=i;
                break;
            }
        }
        return max-min;
    }
};