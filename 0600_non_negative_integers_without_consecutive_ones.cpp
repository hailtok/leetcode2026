// Problem 600: Non-negative Integers without Consecutive Ones
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

class Solution {
public:
    int findIntegers(int n) {
        string s="";
        int temp=n;
        while(temp>0){
            s+=((temp&1)?'1':'0');
            temp>>=1;
        }
        std::reverse(s.begin(),s.end());
        vector<int>dp(31,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<31;++i){
            dp[i]=dp[i-1]+dp[i-2];
        }
        int ans=0,prev=0;
        for(int i=0;i<s.size();++i){
            int bit=s[i]-'0';
            if(bit){
                ans+=dp[s.size()-i-1];
                if(prev){
                    return ans;
                }
                prev=1;
            }
            else{
                prev=0;
            }
        }
        return ans+1;
    }
};