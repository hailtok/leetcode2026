// Problem 409: Longest Palindrome
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>umap;
        for(int i=0;i<s.size();++i){
            ++umap[s[i]];
        }
        int ans=0,odd=0;
        for(auto it=umap.begin();it!=umap.end();++it){
            if(it->second%2==0){
                ans+=it->second;
            }
            else{
                ans+=it->second-1;
                ++odd;
            }
        }
        if(odd>=1){
            ++ans;
        }
        return ans;
    }
};