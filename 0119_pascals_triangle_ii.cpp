// Problem 119: Pascal's Triangle II
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>answer(1,1);
        long long previous=1;
        for(int i=1;i<=rowIndex;++i){
            long long value=previous*(rowIndex-i+1)/i;
            answer.push_back(value);
            previous=value;
        }
        return answer;
    }
};