// Problem 2606: Find the Substring With Maximum Cost
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-substring-with-maximum-cost/

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int>umap;
        for(int i=0;i<chars.size();++i){
            umap[chars[i]]=vals[i];
        }
        int maxsub=0,localsub=0;
        for(int i=0;i<s.size();++i){
            int cur=umap.find(s[i])!=umap.end()?umap[s[i]]:s[i]-'a'+1;
            localsub+=cur;
            maxsub=std::max(maxsub,localsub);
            if(localsub<=0){
                localsub=0;
            }
        }
        return maxsub;
    }
};