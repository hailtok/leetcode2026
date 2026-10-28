// Problem 2351: First Letter to Appear Twice
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/first-letter-to-appear-twice/

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>alpha(26,0);
        char ans='\0';
        for(int i=0;i<s.size();++i){
            if(alpha[s[i]-'a']){
                ans=s[i];
                break;
            }
            else{
                ++alpha[s[i]-'a'];
            }
        }
        return ans;
    }
};