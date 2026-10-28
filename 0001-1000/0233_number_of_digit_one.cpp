// Problem 233: Number of Digit One
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
    int countDigitOne(int n) {
        int ans=0,remand=0;
        long long base=1;
        while(n){
            int temp=n/10;
            if(n%10==1){
                ans+=temp*base+remand+1;
            }
            else if(n%10==0){
                ans+=temp*base;
            }
            else if(n%10>=2){
                ans+=(temp+1)*base;
            }
            remand+=n%10*base;;
            base*=10;
            n/=10;
            cout<<ans<<endl;
        }
        return ans;
    }
};