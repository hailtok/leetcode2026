// Problem 521: Longest Uncommon Subsequence I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/longest-uncommon-subsequence-i/

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b){
            return -1;
        }
        return a.size()>b.size()?a.size():b.size();
    }
};