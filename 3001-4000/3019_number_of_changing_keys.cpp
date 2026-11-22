// Problem 3019: Number of Changing Keys
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/number-of-changing-keys/

class Solution {
public:
    int countKeyChanges(string s) {
        int ans=0;
        char last=tolower(s[0]);
        for(int i=1;i<s.size();++i){
            if(last!=tolower(s[i])){
                cout<<s[i]<<endl;
                ++ans;
            }
            last=tolower(s[i]);
        }
        return ans;
    }
};