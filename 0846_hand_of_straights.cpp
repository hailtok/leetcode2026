// Problem 846: Hand of Straights
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>umap;
        for(int i=0;i<hand.size();++i){
            ++umap[hand[i]];
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it=umap.begin();it!=umap.end();++it){
            pq.push(it->first);
        }
        while(!pq.empty()){
            int count=pq.top();
            if(umap[count]==0){
                pq.pop();
                continue;
            }
            for(int i=0;i<groupSize;++i){
                int next=count+i;
                if(umap[next]==0){
                    return false;
                }
                --umap[next];
            }
        }
        return true;
    }
};