// Problem 403: Frog Jump
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/frog-jump/

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>>umap;
        umap[stones[0]+1]={1};
        for(int i=1;i<stones.size();++i){
            for(auto it=umap[stones[i]].begin();it!=umap[stones[i]].end();++it){
                umap[stones[i]+(*it)].insert((*it));
                umap[stones[i]+(*it)+1].insert((*it)+1);
                umap[stones[i]+(*it)-1].insert((*it)-1);
            }
        }
        return umap[stones.back()].size()!=0;
    }
};