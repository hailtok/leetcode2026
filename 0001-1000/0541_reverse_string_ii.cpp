// Problem 541: Reverse String II
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/reverse-string-ii/

class Solution {
public:
    string reverseStr(string s, int k) {
        int base=0;
        while(base+k<s.size()){
            std::reverse(s.begin()+base,s.begin()+base+k);
            base+=2*k;
        }
        std::reverse(s.begin()+base,s.end());
        return s;
    }
};