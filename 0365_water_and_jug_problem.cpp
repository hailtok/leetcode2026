// Problem 365: Water and Jug Problem
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/water-and-jug-problem/

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target){
            return false;
        }
        if(target==0){
            return true;
        }
        return target%std::__gcd(x,y)==0;
    }
};