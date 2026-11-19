// Problem 2914: Minimum Number of Changes to Make Binary String Beautiful
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        for(int i=0;i<s.size();i+=2){
            if(s[i]!=s[i+1]){
                ++ans;
            }
        }
        return ans;
    }
};