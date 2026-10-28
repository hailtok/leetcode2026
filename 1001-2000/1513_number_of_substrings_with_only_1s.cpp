// Problem 1513: Number of Substrings With Only 1s
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-substrings-with-only-1s/

class Solution {
public:
    int numSub(string s) {
        long output=0,length=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                length++;
            }
            else{
                output%=1000000007;
                output+=(length+1)*length/2;
                length=0;
            }
        }
        output+=(length+1)*length/2;
        output%=1000000007;
        return (int)output;
    }
};