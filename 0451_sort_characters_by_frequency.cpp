// Problem 451: Sort Characters By Frequency
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>umap;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<s.size();++i){
            ++umap[s[i]];
        }
        for(auto it=umap.begin();it!=umap.end();++it){
            pq.push({it->second,it->first});
        }
        s="";
        while(!pq.empty()){
            s+=string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return s;
    }
};