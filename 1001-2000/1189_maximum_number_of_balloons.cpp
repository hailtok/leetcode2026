// Problem 1189: Maximum Number of Balloons
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(int i=0;i<text.size();++i){
            ++mp[text[i]];
        }
        int ans=INT_MAX;
        ans=std::min(std::min(mp['l']/2,mp['o']/2),ans);
        ans=std::min(std::min(mp['b'],std::min(mp['a'],mp['n'])),ans);
        return ans;
    }
};