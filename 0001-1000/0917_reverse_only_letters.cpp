// Problem 917: Reverse Only Letters
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/reverse-only-letters/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        string answer="";
        int left=0,right=s.size()-1;
        while(left<s.size()){
            if(isalpha(s[left])){
                while(!isalpha(s[right])){
                    right--;
                }
                answer+=s[right];
                right--;
            }
            else{
                answer+=s[left];
            }
            left++;
        }
        return answer;
    }
};