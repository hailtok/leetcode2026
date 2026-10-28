// Problem 1529: Minimum Suffix Flips
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-suffix-flips/

class Solution {
public:
    int minFlips(string target) {
        int total=0,all=target.size();
        if(target[0]-'0'){
            total++;
        }
        for(int i=0;i<all-1;i++){
            if(target[i]!=target[i+1]){
                total++;
            }
        }
        return total;
    }
};