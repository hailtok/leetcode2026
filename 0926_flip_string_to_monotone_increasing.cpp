// Problem 926: Flip String to Monotone Increasing
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zeros++;
            }
        }
        int answer=zeros;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zeros--;
                answer=min(answer,zeros);
            }
            else{
                zeros++;
                answer=min(answer,zeros);
            }
            
        }
        return answer;
    }
};