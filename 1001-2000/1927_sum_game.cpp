// Problem 1927: Sum Game
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-game/

class Solution {
public:
    bool sumGame(string num) {
        int score=0,left=0,right=0;
        for(int i=0;i<num.size();++i){
            if(num[i]=='?'){
                if(i<num.size()/2){
                    ++left;
                }
                else{
                    ++right;
                }
            }
            else{
                if(i<num.size()/2){
                    score+=num[i]-'0';
                }
                else{
                    score-=num[i]-'0';
                }
            }
        }
        if(left==right){
            return score!=0?true:false;
        }
        bool ans=false;
        if(score>0){
            if(left>right){
                ans=true;
            }
            else{
                if((right-left)%2==1||(right-left)/2*9!=score){
                    ans=true;
                }
                else{
                    ans=false;
                }
            }
        }
        else{
            if(left>right){
                if((left-right)%2==1||(left-right)/2*9!=-score){
                    ans=true;
                }
                else{
                    ans=false;
                }
            }
            else{
                ans=true;
            }
        }
        return ans;
    }
};