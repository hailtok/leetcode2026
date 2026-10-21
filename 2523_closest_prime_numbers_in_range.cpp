// Problem 2523: Closest Prime Numbers in Range
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/closest-prime-numbers-in-range/

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> nums(right+1, 1);
        for(int i=2; i*i<=right;++i)
        {
            if(nums[i]==1)
            {
                for(int j=i*i; j<=right; j+=i){
                    nums[j]=0;
                }
            }
        }
        vector<int> prime;
        for(int i=max(2,left); i<=right;++i)
        {
            if(nums[i]==1){
                prime.push_back(i);
            }
        }
        vector<int>answer(2,-1);
        int diff=INT_MAX;
        for(int i=1;i<prime.size();++i){
            if(prime[i]-prime[i-1]<diff){
                answer[0]=prime[i-1];
                answer[1]=prime[i];
                diff=prime[i]-prime[i-1];
            }
        }
        return answer;
    }
};