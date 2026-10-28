// Problem 3386: Button with Longest Push Time
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/button-with-longest-push-time/

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int max=events[0][1],index=events[0][0];
        for(int i=1;i<events.size();++i){
            if(max<events[i][1]-events[i-1][1]){
                index=events[i][0];
                max=events[i][1]-events[i-1][1];
            }
            else if(max==events[i][1]-events[i-1][1]){
                index=std::min(index,events[i][0]);
            }
        }
        return index;
    }
};