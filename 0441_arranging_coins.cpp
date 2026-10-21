// Problem 441: Arranging Coins
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        long long start=n;
        return (sqrt(8*start+1)-1)/2;
    }
};