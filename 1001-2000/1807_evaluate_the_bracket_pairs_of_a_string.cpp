// Problem 1807: Evaluate the Bracket Pairs of a String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>umap;
        for(int i=0;i<knowledge.size();++i){
            umap[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                string temp="";
                ++i;
                while(s[i]!=')'){
                    temp+=s[i];
                    ++i;
                }
                if(umap.find(temp)!=umap.end()){
                    ans+=umap[temp];
                }
                else{
                    ans+='?';
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};