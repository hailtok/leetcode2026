// Problem 22: Generate Parentheses
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string>output;
    vector<string> generateParenthesis(int n) {
        recursion(n,n,"");
        return output;
    }
    void recursion(int start,int end,string s){
        if(end==0){
            output.push_back(s);
            return;
        }
        if(start!=0){
            recursion(start-1,end,s+"(");
        }
        if(start<end){
            recursion(start,end-1,s+")");   
        }
    }
};