// Problem 150: Evaluate Reverse Polish Notation
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>Stack;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num1=Stack.top();
                Stack.pop();
                int num2=Stack.top();
                Stack.pop();
                switch(tokens[i][0]){
                    case '+':
                    Stack.push(num1+num2);
                    break;
                    case '-':
                    Stack.push(num2-num1);
                    break;
                    case '*':
                    Stack.push(num1*num2);
                    break;
                    case '/':
                    Stack.push(num2/num1);
                    break;                    
                }
            }
            else{
                Stack.push(stoi(tokens[i]));
            }
        }
        return Stack.top();
    }
};