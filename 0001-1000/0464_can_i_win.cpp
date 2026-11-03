// Problem 464: Can I Win
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/can-i-win/

class Solution {
public:
    unordered_map<int,bool>memo;
    bool dfs(int &maxChoosableInteger,int &desiredTotal,int state,int current){
        if(memo.count(state)){
            return memo[state];
        }
        for (int i=1;i<=maxChoosableInteger;++i) {
            int bit=(1<<i);
            if (!(state&bit)) {
                if(current+i>=desiredTotal||!dfs(maxChoosableInteger,desiredTotal,state|bit, current+i)) {
                    return memo[state]=true;
                }
            }
        }
        return memo[state]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal){
            return false;
        }
        if(desiredTotal<0){
            return true;
        }
        return dfs(maxChoosableInteger,desiredTotal,0,0);
    }
};