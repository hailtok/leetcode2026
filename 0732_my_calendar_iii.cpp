// Problem 732: My Calendar III
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/my-calendar-iii/

class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int count=0,result=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            count+=it->second;
            result=max(count,result);
        }
        return result;
    }
};