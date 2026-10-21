// Problem 415: Add Strings
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string answer="";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int index=0;
        bool carry=false;
        for(int index=0;index<max(num1.size(),num2.size());index++){
            int num1_temp=index<num1.size()?num1[index]-'0':0;
            int num2_temp=index<num2.size()?num2[index]-'0':0;
            int temp=num1_temp+num2_temp+carry;
            if(temp>=10){
                temp-=10;
                carry=true;
            }
            else{
                carry=false;
            }
            answer.push_back(temp+48);
        }
        if(carry){
            answer.push_back('1');
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};