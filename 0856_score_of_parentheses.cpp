// Problem 856: Score of Parentheses
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0,count=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                ++count;
            }
            else{
                --count;
                if(s[i-1]=='('){
                    ans+=1<<count;
                }
            }
        }
        return ans;
    }
};