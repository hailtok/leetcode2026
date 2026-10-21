// Problem 1871: Jump Game VII
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/jump-game-vii/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool>dp(s.size(),false);
        queue<int>queue;
        queue.push(0);
        for(int i=1;i<s.size();++i){
            if(s[i]=='0'){
                while(!queue.empty()&&queue.front()+maxJump<i){
                    queue.pop();
                }
                if(!queue.empty()&&queue.front()+minJump<=i){
                    queue.push(i);
                    dp[i]=true;
                }
            }
        }
        return dp[dp.size()-1];
    }
};