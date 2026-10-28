// Problem 3: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>umap;
        int ans=0,cur=0,buttom=0;
        for(int i=0;i<s.size();++i){
            if(umap.find(s[i])==umap.end()){
                umap[s[i]]=i;
                ++cur;
            }
            else{
                if(umap[s[i]]<buttom){
                    ++cur;
                }
                else{
                    cur=i-umap[s[i]];
                    buttom=umap[s[i]];
                }
                umap[s[i]]=i;
            }
            ans=std::max(ans,cur);
        }
        return ans;
    }
};