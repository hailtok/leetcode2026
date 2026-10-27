// Problem 155: Min Stack
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int>s,min;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min.empty()||min.top()>=val){
            min.push(val);
        }
    }
    
    void pop() {
        if(s.top()==min.top()){
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};