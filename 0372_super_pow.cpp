// Problem 372: Super Pow
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/super-pow/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int total=0,output=1;
        a%=1337;
        for(int i=0;i<b.size();i++){
            total+=b[i];
        }
        while(total!=0){
            total=0;
            if(b[b.size()-1]%2!=0){
                b[b.size()-1]--;
                output=(output*a)%1337;
            }
            a=(a*a)%1337;
            for(int i=0;i<b.size();i++){
                if(b[i]%2!=0){
                    b[i+1]+=10;
                }
                b[i]/=2;
                total+=b[i];
            }
            if(total==1&&b[b.size()-1]==1){
                break;
            }
        }
        return (output%1337)*(a%1337)%1337;
    }
};