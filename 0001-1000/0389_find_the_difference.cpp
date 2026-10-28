// Problem 389: Find the Difference
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> umap;
        for(int i=0;i<s.size();i++){
            umap[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            umap[t[i]]--;
            if(umap[t[i]]<0){
                return t[i];
            }
        }
        return '\0';
    }
};