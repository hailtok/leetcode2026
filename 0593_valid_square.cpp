// Problem 593: Valid Square
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/valid-square/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int max=(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]),index=2;
        if((p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1])>max){
            max=(p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1]);
            index=3;
        }
        if((p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1])>max){
            index=4;
        }
        if(max==0){
            return false;
        }
            
        if(index==2){
            if(p4[0]-p1[0]+p3[0]==p2[0]&&p4[1]-p1[1]+p3[1]==p2[1]&&(p4[0]-p1[0])*(p3[0]-p1[0])+(p4[1]-p1[1])*(p3[1]-p1[1])==0&&(p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1])==(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1])){
                return true;
            }
            else{
                return false;
            }
        }
        else if(index==3){
            if(p2[0]-p1[0]+p4[0]==p3[0]&&p2[1]-p1[1]+p4[1]==p3[1]&&(p2[0]-p1[0])*(p4[0]-p1[0])+(p2[1]-p1[1])*(p4[1]-p1[1])==0&&(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1])==(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1])){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(p3[0]-p1[0]+p2[0]==p4[0]&&p3[1]-p1[1]+p2[1]==p4[1]&&(p3[0]-p1[0])*(p2[0]-p1[0])+(p3[1]-p1[1])*(p2[1]-p1[1])==0&&(p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1])==(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1])){
                return true;
            }
            else{
                return false;
            }
        }
    }
};