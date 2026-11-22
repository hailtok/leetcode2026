// Problem 3648: Minimum Sensors to Cover Grid
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-sensors-to-cover-grid/

class Solution {
public:
    int minSensors(int n, int m, int k) {
        int radius=2*k+1,count=(n/radius+(n%radius==0?0:1))*(m/radius+(m%radius==0?0:1));
        return count;
    }
};