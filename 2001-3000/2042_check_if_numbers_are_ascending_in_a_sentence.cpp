// Problem 2042: Check if Numbers Are Ascending in a Sentence
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/

class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre=0,cur=0;
        for(int i=0;i<s.size();++i){
            if(isdigit(s[i])){
                while(i<s.size()&&isdigit(s[i])){
                    cur*=10;
                    cur+=s[i]-'0';
                    ++i;
                }
                if(cur<=pre){
                    return false;
                }
                pre=cur;
                cur=0;
            }
        }
        return true;
    }
};