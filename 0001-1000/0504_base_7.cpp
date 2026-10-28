// Problem 504: Base 7
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/base-7/

class Solution {
public:
    string convertToBase7(int num) {
        if(num==0){
            return "0";
        }
        bool sign=num<0?true:false;
        num=std::abs(num);
        string ans="";
        while(num>0){
            ans+=(num%7+'0');
            num/=7;
        }
        if(sign){
            ans+='-';
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};