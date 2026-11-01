// Problem 1323: Maximum 69 Number
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int ans=0;
        bool once=false;
        for(int i=0;i<s.size();++i){
            ans*=10;
            if(s[i]=='6'&&!once){
                ans+=9;
                once=true;
            }
            else{
                ans+=s[i]-'0';
            }
        }
        return ans;
    }
};