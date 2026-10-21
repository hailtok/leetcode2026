// Problem 387: First Unique Character in a String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>umap;
        for(char ch:s){
            ++umap[ch];
        }
        for(int i=0;i<s.size();++i){
            if(umap[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};