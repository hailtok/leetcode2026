// Problem 438: Find All Anagrams in a String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    bool check(vector<int>&s,vector<int>&p){
        for(int i=0;i<s.size();++i){
            if(s[i]!=p[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()){
            return {};
        }
        vector<int>alpha(26,0);
        for(int i=0;i<p.size();++i){
            ++alpha[p[i]-'a'];
        }
        vector<int>temp(26,0);
        for(int i=0;i<p.size();++i){
            ++temp[s[i]-'a'];
        }
        vector<int>ans;
        for(int i=p.size();i<s.size();++i){
            if(check(temp,alpha)){
                ans.push_back(i-p.size());
            }
            ++temp[s[i]-'a'];
            --temp[s[i-p.size()]-'a'];
        }
        if(check(temp,alpha)){
            ans.push_back(s.size()-p.size());
        }
        return ans;
    }
};