// Problem 225: Implement Stack using Queues
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int>que;
    MyStack() {

    }
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){
            que.push(que.front());
            que.pop();
        }
    }
    int pop() {
        int top=que.front();
        que.pop();
        return top;
    }
    int top() {
        if(que.empty()){
            return -1;
        }
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};