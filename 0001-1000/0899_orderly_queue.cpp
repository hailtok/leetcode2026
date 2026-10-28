// Problem 899: Orderly Queue
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/orderly-queue/

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string ans=s;
            for(int i=0;i<s.size();++i){
                string new_str=s.substr(1,s.size()-1)+s[0];
                s=new_str;
                if(ans>new_str){
                    ans=new_str;
                }
            }
            return ans;
        }
        std::sort(s.begin(),s.end());
        return s;
    }
};