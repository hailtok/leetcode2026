// Problem 829: Consecutive Numbers Sum
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/consecutive-numbers-sum/

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int base=3,count=2,ans=1;
        while(base<=n){
            if((n-base)%count==0){
                ++ans;
            }
            base+=count+1;
            ++count;
        }
        return ans;
    }
};