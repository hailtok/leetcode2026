// Problem 2177: Find Three Consecutive Integers That Sum to a Given Number
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>output;
        if(num%3!=0){
        }
        else{
            output.push_back(num/3-1);
            output.push_back(num/3);
            output.push_back(num/3+1);
        }
        return output;
    }
};