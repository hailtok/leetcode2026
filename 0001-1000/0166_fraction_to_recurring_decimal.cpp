// Problem 166: Fraction to Recurring Decimal
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        long long n=numerator,d=denominator;
        if(n*d<0){
            ans+='-';
        }
        n=std::abs(n);
        d=std::abs(d);
        ans+=to_string(n/d);
        if(n%d==0){
            return ans;
        }
        else{
            ans+='.';
        }
        n%=d;
        unordered_map<int,int>index;
        while(index.find(n)==index.end()){
            if(n==0){
                return ans;
            }
            index[n]=ans.size();
            n*=10;
            ans+=('0'+n/d);
            n%=d;
        }
        int pos=index[n];
        ans.insert(pos,"(");
        ans+=')';
        return ans;
    }
};