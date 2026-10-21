// Problem 290: Word Pattern
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.size()<=1&&s.size()<=1){
            return true;
        }
        unordered_map<char, string> umap;
        unordered_map<string, char> back_umap;
        string s_temp="";
        int umap_index=0,i=0;
        for(;i<s.size()+1&&umap_index<pattern.size();i++){
            if(i==s.size()||s[i]==' '){
                cout<<s_temp<<endl;
                if(umap.find(pattern[umap_index])!=umap.end()||back_umap.find(s_temp)!=back_umap.end()){
                    if(umap[pattern[umap_index]]!=s_temp){
                        return false;
                    }
                }
                else{
                    umap.insert({pattern[umap_index],s_temp});
                    back_umap.insert({s_temp,pattern[umap_index]});
                }
                s_temp="";
                umap_index++;
            }
            else{
                s_temp+=s[i];
            }
        }
        if(umap_index!=pattern.size()||i!=s.size()+1){
            return false;
        }
        return true;
    }
};