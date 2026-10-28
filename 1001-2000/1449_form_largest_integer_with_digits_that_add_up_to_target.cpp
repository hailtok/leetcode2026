// Problem 1449: Form Largest Integer With Digits That Add up to Target
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int>dp(target+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=target;++i){
            for(int j=0;j<cost.size();++j){
                if(i>=cost[j]){
                    dp[i]=std::max(dp[i],dp[i-cost[j]]+1);
                }
            }
        }
        if(dp[target]<0){
            return "0";
        }
        string ans="";
        int cur=target;
        while(cur>0){
            for(int i=8;i>=0;--i){
                if(cur>=cost[i]&&dp[cur]==dp[cur-cost[i]]+1){
                    ans.push_back((i+1)+'0');
                    cur-=cost[i];
                    break;
                }
            }
        }
        return ans;
    }
};