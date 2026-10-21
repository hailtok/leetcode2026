// Problem 780: Reaching Points
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/reaching-points/

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx&&ty>=sy){
            if(tx==sx&&ty==sy){
                return true;
            }
            if(tx>ty){
                if(sy==ty){
                    return (tx-sx)%ty==0;
                }
                tx%=ty;
            }
            else{
                if(sx==tx){
                    return (ty-sy)%tx==0;
                }
                ty%=tx;
            }
            cout<<tx<<endl;
            cout<<ty<<endl;
        }
        return false;
    }
};