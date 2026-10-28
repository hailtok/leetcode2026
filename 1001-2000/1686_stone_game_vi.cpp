// Problem 1686: Stone Game VI
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/stone-game-vi/

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<aliceValues.size();++i){
            pq.push({aliceValues[i]+bobValues[i],{aliceValues[i],bobValues[i]}});
        }
        bool turn=true;
        int alice_score=0,bob_score=0;
        while(!pq.empty()){
            pair<int,pair<int,int>>stone=pq.top();
            if(turn){
                alice_score+=stone.second.first;
                turn=false;
            }
            else{
                bob_score+=stone.second.second;
                turn=true;
            }
            pq.pop();
        }
        if(alice_score>bob_score){
            return 1;
        }
        else if(alice_score<bob_score){
            return -1;
        }
        return 0;
    }
};