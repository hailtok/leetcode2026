// Problem 397: Integer Replacement
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/integer-replacement/

class Solution {
public:
    int integerReplacement(int n) {
        int step=0;
        long long ren=n;
        while(ren>1){
            if(ren==3){
                step+=2;
                break;
            }
            if(ren%2==0){
                ren/=2;
            }
            else{
                if((ren+1)%4==0){
                    ren++;
                }
                else{
                    ren--;
                }
            }
            step++;
        }
        return step;
    }
};