// Problem 3016: Minimum Number of Pushes to Type Word II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

class Solution {
public:
    int minimumPushes(string word) {
        vector<int>alpha(26);
        for(int i=0;i<word.size();++i){
            ++alpha[word[i]-'a'];
        }
        std::sort(alpha.rbegin(),alpha.rend());
        int ans=0;
        for(int i=0;i<alpha.size();++i){
            ans+=alpha[i]*(i/8+1);
        }
        return ans;
    }
};