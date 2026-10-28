// Problem 459: Repeated Substring Pattern
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/repeated-substring-pattern/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s+s;
        return  t.substr(1,t.size()-2).find(s)!=std::string::npos;
    }
};