// Problem 20: Valid Parentheses
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                Stack.push(s[i]);
            }
            else{
                if(Stack.empty()||(Stack.top()=='('&&s[i]!=')')||(Stack.top()=='['&&s[i]!=']')||(Stack.top()=='{'&&s[i]!='}')){
                    return false;
                }
                Stack.pop();
            }
        }
        if(Stack.size()!=0){
            return false;
        }
        else{
            return true;
        }
    }
};