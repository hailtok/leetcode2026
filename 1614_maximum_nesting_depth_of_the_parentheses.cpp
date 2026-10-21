// Problem 1614: Maximum Nesting Depth of the Parentheses
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int count=0,ans=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                ++count;
                ans=std::max(ans,count);
            }
            if(s[i]==')'){
                --count;
            }
        }
        return ans;
    }
};