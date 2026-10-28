// Problem 3178: Find the Child Who Has the Ball After K Seconds
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/

class Solution {
public:
    int numberOfChild(int n, int k) {
        return (k/(n-1))%2==0?k%(n-1):n-k%(n-1)-1;
    }
};