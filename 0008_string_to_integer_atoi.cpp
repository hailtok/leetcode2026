// Problem 8: String to Integer (atoi)
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0){
            return 0;
        }
        long long ans=0;
        int negative=1,index=0;
        while(index<s.size()&&s[index]==' '){
            ++index;
        }
        if(s[index]=='-'||s[index]=='+'){
            if(s[index]=='-'){
                negative*=-1;
            }
            ++index;
        }
        while(index<s.size()&&s[index]=='0'){
            ++index;
        }
        while(index<s.size()&&isdigit(s[index])){
            ans*=10;
            ans+=s[index]-'0';
            if(ans>INT_MAX){
                break;
            }
            ++index;
        }
        ans*=negative;
        if(ans>INT_MAX){
            ans=INT_MAX;
        }
        if(ans<INT_MIN){
            ans=INT_MIN;
        }
        return (int)ans;
    }
};