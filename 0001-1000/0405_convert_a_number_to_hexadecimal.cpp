// Problem 405: Convert a Number to Hexadecimal
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/convert-a-number-to-hexadecimal/

class Solution {
public:
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        unsigned int t=num;
        string ans="";
        while(t>0){
            int mod=t&15;
            if(mod>9){
                ans+=(mod-10+'a');
            }
            else{
                ans+=(mod+'0');
            }
            t>>=4;
        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};