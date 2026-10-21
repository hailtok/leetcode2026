// Problem 2186: Minimum Number of Steps to Make Two Strings Anagram II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>alphabet(26);
        int output=0;
        for(int i=0;i<s.size();i++){
            alphabet[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            alphabet[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            output+=abs(alphabet[i]);
        }
        return output;
    }
};