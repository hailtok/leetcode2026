// Problem 2124: Check if All A's Appears Before All B's
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

class Solution {
public:
    bool checkString(string s) {
        bool ans=true;
        for(int i=0;i<s.size();++i){
            if(s[i]!='a'){
                for(int j=i+1;j<s.size();++j){
                    if(s[j]=='a'){
                        ans=false;
                        break;
                    }
                }
                break;
            }
        }
        return ans;
    }
};