// Problem 1573: Number of Ways to Split a String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-ways-to-split-a-string/

class Solution {
public:
    int numWays(string s) {
        int ones=0,partition_index=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        if(ones==0){
            return (s.size()-1)*(s.size()-2)/2%1000000007;
        }
        if(ones%3!=0){
            return 0;
        }
        else{
            ones/=3;
        }
        long index=0,count1=0,count2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                index++;
            }
            if(index==ones){
                count1++;
            }
            if(index==ones*2){
                count2++;
            }
        }
        return (int)(count1*count2%1000000007);
    }
};