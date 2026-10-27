// Problem 2409: Count Days Spent Together
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/count-days-spent-together/

class Solution {
public:
    int days(const string &s){
        static constexpr int month[12]={0,31,59,90,120,151,181,212,243,273,304,334};
        int m=stoi(s.substr(0,2)),d=stoi(s.substr(3,2));
        return month[m-1]+d;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start=std::max(days(arriveAlice),days(arriveBob));
        int end=std::min(days(leaveAlice),days(leaveBob));
        return std::max(end-start+1,0);
    }
};