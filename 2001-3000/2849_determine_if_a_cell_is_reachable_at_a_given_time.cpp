// Problem 2849: Determine if a Cell Is Reachable at a Given Time
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx&&sy==fy){
            if(t==1){
                return false;
            }
            else{
                return true;
            }
        }
        t-=max(abs(sx-fx),abs(sy-fy));
        if(t>=0){
            return true;
        }
        else{
            return false;
        }
    }
};