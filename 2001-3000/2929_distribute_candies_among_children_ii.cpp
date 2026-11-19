// Problem 2929: Distribute Candies Among Children II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/distribute-candies-among-children-ii/

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0;i<=std::min(n,limit);++i){
            if(n-i<=2*limit){
                ans+=std::min(n-i,limit)-std::max(0,n-i-limit)+1;
            }
        }
        return ans;
    }
};