// Problem 3461: Check If Digits Are Equal in String After Operations I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()!=2){
            string temp="";
            for(int i=1;i<s.size();++i){
                temp.push_back(((s[i]-'0')+(s[i-1]-'0'))%10);
            }
            s=temp;
        }
        return s[0]==s[1]?true:false;
    }
};