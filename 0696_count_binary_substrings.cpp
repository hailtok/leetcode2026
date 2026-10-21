// Problem 696: Count Binary Substrings
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/count-binary-substrings/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0,current=1,previous=0;
        for(int i=1;i<s.size();++i){
            if(s[i]==s[i-1]){
                ++current;
            }
            else{
                ans+=std::min(current,previous);
                previous=current;
                current=1;
            }
        }
        return ans+std::min(current,previous);;
    }
};