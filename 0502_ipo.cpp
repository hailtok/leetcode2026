// Problem 502: IPO
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>projects;
        for(int i=0;i<profits.size();++i){
            projects.push_back({capital[i],profits[i]});
        }
        std::sort(projects.begin(),projects.end());
        priority_queue<int>pq;
        for(int i=0,index=0;i<k;++i){
            while(index<projects.size()&&w>=projects[index].first){
                pq.push(projects[index].second);
                ++index;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};