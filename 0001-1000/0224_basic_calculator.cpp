// Problem 224: Basic Calculator
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        stack<int>num_stack;
        int temp=0,sign=1,answer=0;
        for(int i=0;i<s.size();++i){
            if(isdigit(s[i])){
                temp=temp*10+(s[i]-'0');
            }
            if(s[i]=='+'){
                answer+=sign*temp;
                temp=0;
                sign=1;
            }
            if(s[i]=='-'){
                answer+=sign*temp;
                sign=-1;
                temp=0;
            }
            if(s[i]=='('){
                num_stack.push(answer);
                num_stack.push(sign);
                answer=0;
                sign=1;
            }
            if(s[i]==')'){
                answer+=sign*temp;
                answer*=num_stack.top();
                num_stack.pop();
                answer+=num_stack.top();
                num_stack.pop();
                temp=0;
            }
        }
        return answer+sign*temp;
    }
};