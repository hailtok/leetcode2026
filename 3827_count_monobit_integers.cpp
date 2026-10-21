// Problem 3827: Count Monobit Integers
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/count-monobit-integers/

class Solution {
public:
    int countMonobit(int n) {
        int ones=1,ans=1;
        while(n>=ones){
            ones<<=1;
            ++ones;
            ++ans;
        }
        return ans;
    }
};