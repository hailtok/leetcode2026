// Problem 458: Poor Pigs
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/poor-pigs/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets)/log2(int(minutesToTest/minutesToDie)+1));
    }
};