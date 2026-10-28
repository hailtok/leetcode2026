// Problem 731: My Calendar II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/my-calendar-ii/

class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int count=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            count+=it->second;
            if(count==3){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */