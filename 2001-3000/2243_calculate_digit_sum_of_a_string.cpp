// Problem 2243: Calculate Digit Sum of a String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/calculate-digit-sum-of-a-string/

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int times=s.size()/k+(s.size()%k!=0?1:0);
            string new_s;
            for(int i=0;i<times;++i){
                int t=0;
                for(int j=0;j<k;++j){
                    t+=i*k+j>=s.size()?0:s[i*k+j]-'0';
                }
                new_s+=to_string(t);
            }
            s=new_s;
        }
        return s;
    }
};