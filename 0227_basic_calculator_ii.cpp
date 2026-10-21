// Problem 227: Basic Calculator II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
    int calculate(string s) {
        stack<int>nums;
        int cur=0;
        bool sub=false,mul=false,div=false;
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){
                continue;
            }
            if(isdigit(s[i])){
                cur*=10;
                cur+=s[i]-'0';
            }
            else{
                if(sub){
                    cur=-cur;
                    sub=false;
                }
                if(mul||div){
                    cur=mul?nums.top()*cur:nums.top()/cur;
                    mul=false;
                    div=false;
                    nums.pop();
                }
                if(s[i]=='-'){
                    sub=true;
                }
                else if(s[i]=='*'){
                    mul=true;
                }
                else if(s[i]=='/'){
                    div=true;
                }
                nums.push(cur);
                cur=0;
            }
        }
        if(sub){
            cur=-cur;
        }
        if(mul||div){
            cur=mul?nums.top()*cur:nums.top()/cur;
            nums.pop();
        }
        int ans=cur;
        while(!nums.empty()){
            ans=nums.top()+ans;
            nums.pop();
        }
        return ans;
    }
};