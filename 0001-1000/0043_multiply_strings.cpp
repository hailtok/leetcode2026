// Problem 43: Multiply Strings
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return"0";
        }
        vector<int>temp(num1.size()+num2.size());
        for(int i=num1.size()-1;i>=0;--i){
            for(int j=num2.size()-1;j>=0;--j){
                temp[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                temp[i+j]+=temp[i+j+1]/10;
                temp[i+j+1]%=10;
            }
        }
        string answer="";
        int index=0;
        while(index<temp.size()&&temp[index]==0){
            ++index;
        }
        while(index<temp.size()){
            answer.push_back(temp[index]+'0');
            ++index;
        }
        return answer;
    }
};