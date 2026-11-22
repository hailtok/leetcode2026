// Problem 1012: Numbers With Repeated Digits
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/numbers-with-repeated-digits/

class Solution {
public:
    string s;
    int dp[12][1024][2][2];
    int dfs(int pos,int mask,bool isTight,bool isStarted){
        if(pos==s.size()){
            return isStarted?1:0;
        }
        if(dp[pos][mask][isTight][isStarted]!=-1){
            return dp[pos][mask][isTight][isStarted];
        }
        int limit=isTight?s[pos]-'0':9;
        long long res=0;
        for(int d=0;d<=limit;++d){
            bool nextTight=isTight&&(d==limit);
            if(!isStarted&&d==0){
                res+=dfs(pos+1,mask,nextTight,false);
            }
            else{
                if((mask>>d)&1){
                    continue;
                }
                res+=dfs(pos+1,mask|(1<<d),nextTight,true);
            }
        }
        return dp[pos][mask][isTight][isStarted]=(int)res;
    }    
    int numDupDigitsAtMostN(int n) {
        s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int unique=dfs(0,0,true,false);
        return n-unique;
    }
};