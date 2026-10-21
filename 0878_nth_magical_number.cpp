// Problem 878: Nth Magical Number
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/nth-magical-number/

class Solution {
public:
    int lcd(int num1,int num2){
        return (num1*num2)/gcd(num1,num2);
    }
    int gcd(int num1,int num2){
        if(num2==0){
            return num1;
        }
        return gcd(num2,num1%num2);
    }
    int nthMagicalNumber(int n, int a, int b) {
        --n;
        int temp1=a,temp2=b,mod=1e9+7;
        long long ans=0,num=lcd(a,b);
        ans+=num*(n/(num/a+num/b-1));
        ans%=mod;
        n%=(num/a+num/b-1);
        while(n!=0){
            if(temp1>temp2){
                temp2+=b;
            }
            else{
                temp1+=a;
            }
            --n;
        }
        return (ans+std::min(temp1,temp2))%mod;
    }
};