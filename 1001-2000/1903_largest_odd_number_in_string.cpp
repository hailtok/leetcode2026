// Problem 1903: Largest Odd Number in String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string num) {
        string ans="",temp="";
        for(int i=0;i<num.size();++i){
            temp+=num[i];
            if((num[i]-'0')%2){
                ans=temp;
            }
        }
        return ans;
    }
};