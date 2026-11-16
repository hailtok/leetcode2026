// Problem 848: Shifting Letters
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/shifting-letters/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int>prefix(s.size(),0);
        prefix.back()=shifts.back();
        for(int i=prefix.size()-2;i>=0;--i){
            prefix[i]=(prefix[i+1]+shifts[i])%26;
        }
        for(int i=0;i<s.size();++i){
            s[i]=(s[i]-'a'+prefix[i])%26+'a';
        }
        return s;
    }
};