// Problem 1358: Number of Substrings Containing All Three Characters
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int left=0,right=0,ans=0;
        while(right<s.size()){
            ++mp[s[right]];
            while(mp.size()==3){
                ans+=s.size()-right;
                --mp[s[left]];
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                ++left;
            }
            ++right;
        }
        return ans;
    }
};