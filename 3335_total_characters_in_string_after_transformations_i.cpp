// Problem 3335: Total Characters in String After Transformations I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>count(26);
        int quotient=t/26,remainder=t%26,mod=1e9+7;
        for(int i=0;i<s.size();++i){
            int index=s[i]-'a'+remainder;
            if(index>=26){
                ++count[index-26];
                ++count[index-25];
            }
            else{
                ++count[index];
            }
        }
        int ans=0;
        while(quotient--){
            vector<int>temp(26);
            for(int i=0;i<25;++i){
                temp[i]+=count[i]%mod;
                temp[i+1]+=count[i]%mod;
                temp[i]%=mod;
                temp[i+1]%=mod;
            }
            temp[0]+=count[25]%mod;
            temp[1]+=count[25]%mod;
            temp[25]+=count[25]%mod;
            count=temp;
        }
        for(int i=0;i<26;++i){
            ans+=count[i]%mod;
            ans%=mod;
        }
        return ans%mod;
    }
};