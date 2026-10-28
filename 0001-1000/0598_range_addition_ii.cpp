// Problem 598: Range Addition II
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a=m,b=n;
        for(auto &op:ops){
            a=std::min(a,op[0]);
            b=std::min(b,op[1]);
        }
        return a*b;
    }
};