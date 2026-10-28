// Problem 624: Maximum Distance in Arrays
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-distance-in-arrays/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq1;
        priority_queue<pair<int,int>>pq2;
        for(int i=0;i<arrays.size();++i){
            pq1.push({arrays[i][0],i});
            pq2.push({arrays[i].back(),i});
        }
        pair<int,int>p1=pq1.top(),p2=pq2.top();
        pq1.pop();
        pq2.pop();
        int ans=p2.first-p1.first;
        if(p1.second==p2.second){
            ans=pq2.top().first-p1.first;
            ans=std::max(ans,p2.first-pq1.top().first);
        }
        return ans;
    }
};