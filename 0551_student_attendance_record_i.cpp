// Problem 551: Student Attendance Record I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/student-attendance-record-i/

class Solution {
public:
    bool checkRecord(string s) {
        int late=0,absence=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                late++;
                if(late==3){
                    return false;
                }
            }
            else{
                late=0;
                if(s[i]=='A'){
                    absence++;
                    if(absence==2){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};