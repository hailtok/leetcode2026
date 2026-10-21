// Problem 3174: Clear Digits
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/clear-digits/

class Solution {
public:
    string clearDigits(string s) {
        stack<char>stack;
        for(int i=0;i<s.size();++i){
            if(isalpha(s[i])){
                stack.push(s[i]);
            }
            else{
                stack.pop();
            }
        }
        string answer="";
        while(!stack.empty()){
            answer+=stack.top();
            stack.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};