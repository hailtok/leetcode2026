// Problem 2379: Minimum Recolors to Get K Consecutive Black Blocks
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int answer=INT_MAX,black=0;
        for(int i=0;i<blocks.size();++i){
            if(i-k>=0&&blocks[i-k]=='B'){
                black--;
            }
            if(blocks[i]=='B'){
                black++;
            }
            answer=std::min(answer,k-black);
        }
        return answer;
    }
};