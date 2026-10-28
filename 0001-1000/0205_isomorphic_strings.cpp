// Problem 205: Isomorphic Strings
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char>umap;
        unordered_map<char,char>back_umap;
        for(int i=0;i<s.size();i++){
            if(umap.find(s[i])==umap.end()){
                if(back_umap.find(t[i])==back_umap.end()){
                    umap.insert({s[i],t[i]});
                    back_umap.insert({t[i],s[i]});
                }
                else if(back_umap[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                if(t[i]!=umap[s[i]]){
                    return false;
                }
            }
        }
        return true;
    }
};