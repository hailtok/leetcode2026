// Problem 557: Reverse Words in a String III
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int last=0;
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){
                std::reverse(s.begin()+last,s.begin()+i);
                last=i+1;
            }
        }
        std::reverse(s.begin()+last,s.end());
        return s;
    }
};