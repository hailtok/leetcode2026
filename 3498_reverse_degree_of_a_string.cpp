// Problem 3498: Reverse Degree of a String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/reverse-degree-of-a-string/

class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();++i){
            ans+=(26-(s[i]-'a'))*(i+1);
        }
        return ans;
    }
};