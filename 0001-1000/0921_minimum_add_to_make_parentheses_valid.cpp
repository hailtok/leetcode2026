// Problem 921: Minimum Add to Make Parentheses Valid
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,count=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                ++count;
            }
            else{
                --count;
            }
            if(count<0){
                ++ans;
                count=0;
            }
        }
        return ans+count;
    }
};