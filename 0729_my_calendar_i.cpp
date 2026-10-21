// Problem 729: My Calendar I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/my-calendar-i/

class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->first<end&&start<it->second){
                return false;
            }
        }
        mp.insert({start,end});
        return true;
    }
};




class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        auto next=mp.upper_bound(start);
        if(next!=mp.end()&&next->second<end){
            return false;
        }
        mp.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */