// Problem 76: Minimum Window Substring
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        queue<pair<int,int>>dp;
        unordered_map<char,int>umap;
        for(int i=0;i<t.size();++i){
            ++umap[t[i]];
        }
        string ans="";
        int count=0;
        for(int i=0;i<s.size();++i){
            if(umap.find(s[i])==umap.end()){
                continue;
            }
            else {
                dp.push({s[i],i});
                if(umap[s[i]]>0){
                    ++count;
                }
                --umap[s[i]];
            }
            if(count==t.size()){
                while(umap[dp.front().first]<0){
                    ++umap[dp.front().first];
                    dp.pop();
                }
                string temp=s.substr(dp.front().second,i-dp.front().second+1);
                if(ans.empty()||ans.size()>temp.size()){
                    ans=temp;
                }
            }
        }
        return ans;
    }
};