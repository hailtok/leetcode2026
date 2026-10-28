// Problem 151: Reverse Words in a String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        string temp,ans="";
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]!=' '){
                temp+=s[i];
            }
            if(s[i]==' '&&temp.size()!=0){
                std::reverse(temp.begin(),temp.end());
                ans+=temp+" ";
                temp.clear();
            }
        }
        if(temp.size()!=0){
            std::reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        else{
            ans.pop_back();
        }
        return ans;
    }
};