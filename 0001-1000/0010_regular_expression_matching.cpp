// Problem 10: Regular Expression Matching
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_i=0,p_i=0;
        while(s_i<s.size()||p_i<p.size()){
            char ch=p_i<p.size()?p[p_i]:'\0';
            bool dot=p_i+1<p.size()&&p[p_i+1]=='*'?true:false;
            if(ch=='.'&&s_i<s.size()){
                if(dot){
                    bool check=false;
                    for(int i=s_i;i<=s.size()&&p_i+2<=p.size()&&!check;++i){
                        check=isMatch(s.substr(i),p.substr(p_i+2));
                    }
                    if(check){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                ++s_i;
                ++p_i;
            }
            else if(s[s_i]==ch){
                if(dot){
                    bool check=isMatch(s.substr(s_i),p.substr(p_i+2));
                    for(int i=s_i;i<s.size()&&s[i]==p[p_i]&&p_i+2<=p.size()&&!check;++i){
                        check=isMatch(s.substr(i+1),p.substr(p_i+2));
                    }
                    if(check){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    ++s_i;
                    ++p_i;
                }
            }
            else{
                if(dot){
                    p_i+=2;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};