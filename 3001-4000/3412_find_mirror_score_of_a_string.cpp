// Problem 3412: Find Mirror Score of a String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-mirror-score-of-a-string/

class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>>previous(26);
        long long answer=0;
        for(int i=0;i<s.size();++i){
            if(previous[25-s[i]+'a'].size()!=0){
                answer+=i-previous[25-s[i]+'a'].back();
                previous[25-s[i]+'a'].pop_back();
            }
            else{
                previous[s[i]-'a'].push_back(i);
            }
        }
        return answer;
    }
};