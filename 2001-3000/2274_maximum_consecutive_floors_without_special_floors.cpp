// Problem 2274: Maximum Consecutive Floors Without Special Floors
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int answer=std::max(special[0]-bottom,top-special.back()),count=0;
        for(int i=0;i<special.size()-1;++i){
            count=special[i+1]-special[i]-1;
            answer=std::max(answer,count);
        }
        return answer;
    }
};