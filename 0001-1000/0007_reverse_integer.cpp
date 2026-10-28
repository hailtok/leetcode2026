// Problem 7: Reverse Integer
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        long output=0;
        bool negative=true;
        if(x<0){
           negative=false; 
        }
        x=abs(x);
        while(x>=10){
            output*=10;
            output+=x%10;
            x/=10;
            if(output>INT_MAX||output<INT_MIN){
                return 0;
            }
        }
        output*=10;
        output+=x;
        if(output>INT_MAX||output<INT_MIN){
            return 0;
        }
        if(!negative){
            output=-output;
        }
        return output;
    }
};