// Problem 948: Bag of Tokens
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==1){
            return power>=tokens[0];
        }
        sort(tokens.begin(),tokens.end());
        int score=0;
        for(int begin=0,last=tokens.size()-1,check=last-begin;begin<last;){
            if(score>0){
                power+=tokens[last];
                score--;
                last--;
            }
            while(power>=tokens[begin]){
                score++;
                power-=tokens[begin];
                begin++;
            }
            if(check==last-begin){
                return score;
            }
            else{
                check=last-begin;
            }
        }
        return score;
    }
};