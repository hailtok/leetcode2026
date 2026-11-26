// Problem 1417: Reformat The String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/reformat-the-string/

class Solution {
public:
    string reformat(string s) {
        string alpha="",num="";
        for(int i=0;i<s.size();++i){
            if(isalpha(s[i])){
                alpha+=s[i];
            }
            else{
                num+=s[i];
            }
        }
        if(std::abs((int)alpha.size()-(int)num.size())>=2){
            return "";
        }
        string ans="";
        if(alpha.size()>num.size()){
            ans+=alpha.back();
            alpha.pop_back();
            for(int i=0;i<num.size();++i){
                ans+=num[i];
                ans+=alpha[i];
            }
        }
        else if(alpha.size()<num.size()){
            ans+=num.back();
            num.pop_back();
            for(int i=0;i<num.size();++i){
                ans+=alpha[i];
                ans+=num[i];
            }
        }
        else{
            for(int i=0;i<num.size();++i){
                ans+=alpha[i];
                ans+=num[i];
            }
        }
        return ans;
    }
};