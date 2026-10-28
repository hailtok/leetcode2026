// Problem 65: Valid Number
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string s) {
        bool sign=true,num=false,dot=false,e=false;
        for(int i=0;i<s.size();++i){
            if((s[i]=='+'||s[i]=='-') &&sign){
                sign=false;
                continue;
            }
            sign=false;
            if(s[i]=='.'){
                if(!e&&!dot){
                    dot=true;
                }
                else{
                    return false;
                }
                continue;
            }
            if(s[i]=='e'||s[i]=='E'){
                if(!e&&num){
                    e=true;
                }
                else{
                    return false;
                }
                sign=true;
                num=false;
                continue;
            }
            if(isdigit(s[i])){
                num=true;
                continue;
            }
            return false;
        }
        return num;
    }
};