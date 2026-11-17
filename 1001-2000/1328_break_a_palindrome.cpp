// Problem 1328: Break a Palindrome
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    bool is_palindrome(string s){
        for(int i=0;i<s.size()/2;++i){
            if(s[i]!=s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1){
            return "";
        }
        string ans="";
        for(int i=0;i<palindrome.size();++i){
            if(palindrome[i]!='a'){
                ans=palindrome;
                ans[i]='a';
                if(!is_palindrome(ans)){
                    return ans;
                }
            }
        }
        ++palindrome.back();
        return palindrome;
    }
};