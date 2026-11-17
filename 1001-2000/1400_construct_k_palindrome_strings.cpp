// Problem 1400: Construct K Palindrome Strings
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/construct-k-palindrome-strings/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k){
            return false;
        }
        vector<int>alpha(26,0);
        for(int i=0;i<s.size();++i){
            ++alpha[s[i]-'a'];
        }
        for(int i=0;i<26;++i){
            if(alpha[i]%2!=0){
                --k;
            }
        }
        return k>=0?true:false;
    }
};