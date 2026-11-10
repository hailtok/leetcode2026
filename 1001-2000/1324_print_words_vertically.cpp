// Problem 1324: Print Words Vertically
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/print-words-vertically/

class Solution {
public:
    vector<string>s_split(string s){
        string temp="";
        vector<string>output;
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){
                output.push_back(temp);
                temp.clear();
            }
            else{
                temp+=s[i];
            }
        }
        output.push_back(temp);
        return output;
    }
    vector<string> printVertically(string s) {
        vector<string>vertical_s=s_split(s);
        int max_length=0;
        for(int i=0;i<vertical_s.size();++i){
            max_length=std::max(max_length,(int)vertical_s[i].size());
        }
        vector<string>ans(max_length);
        cout<<max_length<<endl;
        for(int i=0;i<max_length;++i){
            string t="";
            for(int j=0;j<vertical_s.size();++j){
                if(i<vertical_s[j].size()){
                   t+=vertical_s[j][i]; 
                }
                else{
                    t+=" ";
                }
            }
            for(int i=t.size()-1;i>=0;--i){
                if(t[i]==' '){
                    t.pop_back();
                }
                else{
                    break;
                }
            }
            ans[i]=t;
        }
        return ans;
    }
};