// Problem 1347: Minimum Number of Steps to Make Two Strings Anagram
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>temp(26);
        int output=0;
        for(int i=0;i<s.size();i++){
            temp[s[i]-'a']++;
            temp[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            output+=abs(temp[i]);
        }
        return output/2;
    }
};