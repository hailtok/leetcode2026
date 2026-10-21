// Problem 2486: Append Characters to String to Make Subsequence
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

class Solution {
public:
    int appendCharacters(string s, string t) {
        int answer=t.size();
        for(int i=0,j=0;i<s.size()&&j<t.size();i++){
            if(s[i]==t[j]){
                answer--;
                j++;
            }
        }
        return answer;
    }
};