// Problem 1007: Minimum Domino Rotations For Equal Row
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
public:
    int cal(vector<int>&tops,vector<int>&bottoms,int candi){
        int top=0,bottom=0;
        for(int i=0;i<tops.size();++i){
            if(tops[i]!=candi){
                ++top;
            }
            if(bottoms[i]!=candi){
                ++bottom;
            }
            if(tops[i]!=candi&&bottoms[i]!=candi){
                return -1;
            }
        }
        return std::min(top,bottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int candidate1=tops[0],candidate2=bottoms[0],ans1=cal(tops,bottoms,candidate1),ans2=cal(tops,bottoms,candidate2);
        if(ans1==-1){
            if(ans2==-1){
                return -1;
            }
            return ans2;
        }
        else if(ans2==-1){
            return ans1;
        }
        return std::min(ans1,ans2);
        
    }
};