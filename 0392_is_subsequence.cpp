// Problem 392: Is Subsequence
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==""){
            return true;
        }
        for(int i=0,j=0;i<t.size();i++){
            if(s[j]==t[i]){
                j++;
                if(j==s.size()){
                    return true;
                }
            }
        }
        return false;
    }
};