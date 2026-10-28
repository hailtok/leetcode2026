// Problem 1017: Convert to Base -2
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/convert-to-base-2/

class Solution {
public:
    string baseNeg2(int N) {
        int two=1;
        string output;
        while(N){
            int a=N%(-2);
            N/=(-2);
            if(a<0){
                a+=2;
                N++;
            }
            output=to_string(a)+output;
        }
        if(output==""){
            return "0";
        }
        return output;
    }
};