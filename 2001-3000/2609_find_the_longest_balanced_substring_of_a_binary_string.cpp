// Problem 2609: Find the Longest Balanced Substring of a Binary String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zero=0,ones=0,index=0,ans=0;
        while(index<s.size()){
            if(s[index]=='0'){
                ++zero;
                ++index;
            }
            if(s[index]=='1'){
                while(index<s.size()&&s[index]=='1'){
                    ++ones;
                    ans=std::max(std::min(zero,ones)*2,ans);
                    ++index;
                }
                zero=0;
                ones=0;
            }
        }
        return ans;
    }
};