// Problem 383: Ransom Note
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>alphabet(26);
        for(int i=0;i<ransomNote.size();i++){
            alphabet[ransomNote[i]-'a']++;
        }
        for(int i=0;i<magazine.size();i++){
            alphabet[magazine[i]-'a']--;
        }
        for(int i=0;i<alphabet.size();i++){
            if(alphabet[i]>0){
                return false;
            }
        }
        return true;
    }
};