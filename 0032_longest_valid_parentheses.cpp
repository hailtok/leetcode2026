// Problem 32: Longest Valid Parentheses
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int>stack;
        stack.push(-1);
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                stack.push(i);
            }
            else{
                stack.pop();
                if(stack.empty()){
                    stack.push(i);
                }
                else{
                    ans=std::max(ans,i-stack.top());
                }
            }
        }
        return ans;
    }
};