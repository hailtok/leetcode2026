// Problem 670: Maximum Swap
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    int maximumSwap(int num) {
        string input=to_string(num);
        vector<int>number(10);
        for(int i=0;i<input.size();i++){
            number[input[i]-'0']=i;
        }
        for(int i=0;i<input.size();i++){
            for(int j=9;j>input[i]-'0';j--){
                if(number[j]>i){
                    swap(input[i],input[number[j]]);
                    return stoi(input);
                }
            }
        }
        return stoi(input);
    }
};