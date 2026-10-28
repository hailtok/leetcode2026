// Problem 30: Substring with Concatenation of All Words
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>umap;
        vector<int>ans;
        int gap=words[0].size();
        for(int i=0;i<words.size();++i){
            ++umap[words[i]];
        }
        for(int i=0;i<gap;++i){
            int left=i,right=i;
            unordered_map<string,int>seen;
            int count=0;
            while(right+gap<=s.size()){
                string temp=s.substr(right,gap);
                right+=gap;
                if(umap.count(temp)){
                    ++seen[temp];
                    ++count;
                    while(seen[temp]>umap[temp]){
                        string left_word=s.substr(left,gap);
                        --seen[left_word];
                        --count;
                        left+=gap;
                    }
                    if(count==words.size()){
                        ans.push_back(left);
                    }
                }
                else{
                    seen.clear();
                    count=0;
                    left=right;
                }
            }
        }
        return ans;
    }
};