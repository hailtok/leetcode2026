// Problem 3014: Minimum Number of Pushes to Type Word I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/

class Solution {
public:
    int minimumPushes(string word) {
        int count=word.size(),ans=0,m=1;
        while(count>8){
            ans+=8*m;
            count-=8;
            ++m;
        }
        return ans+m*count;
    }
};