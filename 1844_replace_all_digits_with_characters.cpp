// Problem 1844: Replace All Digits with Characters
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/replace-all-digits-with-characters/

class Solution {
public:
    string replaceDigits(string s) {
        char t='\0';
        for(int i=0;i<s.size();++i){
            isalpha(s[i])?t=s[i]:s[i]=(t+s[i]-'0');
        }
        return s;
    }
};