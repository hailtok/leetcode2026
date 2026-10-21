// Problem 973: K Closest Points to Origin
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<points.size();++i){
            int cur_dis=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({cur_dis,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};