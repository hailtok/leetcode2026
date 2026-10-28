// Problem 3340: Check Balanced String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/check-balanced-string/

class Solution {
public:
    bool isBalanced(string num) {
        int nums=0;
        for(int i=0;i<num.size();++i){
            i%2==0?nums-=num[i]-'0':nums+=num[i]-'0';
        }
        return nums==0;
    }
};