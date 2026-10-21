// Problem 242: Valid Anagram
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>alphabet(26);
        for(int i=0;i<s.size();i++){
            alphabet[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            alphabet[t[i]-'a']--;
        }
        for(int i=0;i<alphabet.size();i++){
            if(alphabet[i]!=0){
                return false;
            }
        }
        return true;
    }
};