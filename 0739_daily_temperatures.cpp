// Problem 739: Daily Temperatures
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>output(T.size());
        stack<int>stack;
        for(int i=0;i<T.size();i++){
            while(!stack.empty()&&T[i]>T[stack.top()]){
                int out=stack.top();
                stack.pop();
                output[out]=i-out;
            }
            stack.push(i);
        }
        return output;
    }
};