// Problem 1054: Distant Barcodes
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>umap;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<barcodes.size();++i){
            ++umap[barcodes[i]];
        }
        for(auto it=umap.begin();it!=umap.end();++it){
            pq.push({it->second,it->first});
        }
        vector<int>ans(barcodes.size());
        for(int i=0;i<barcodes.size()-1;i+=2){
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();
            ans[i]=p1.second;
            ans[i+1]=p2.second;
            --p1.first;
            --p2.first;
            pq.push(p1);
            pq.push(p2);
        }
        if(barcodes.size()%2!=0){
            ans.back()=pq.top().second;
        }
        return ans;
    }
};