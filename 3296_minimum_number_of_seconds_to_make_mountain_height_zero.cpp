// Problem 3296: Minimum Number of Seconds to Make Mountain Height Zero
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>> >pq;
        for(int i=0;i<workerTimes.size();++i){
            pq.push({workerTimes[i],{workerTimes[i],2}});
        }
        long long ans=0;
        while(mountainHeight--){
            long long first=pq.top().first,base=pq.top().second.first,round=pq.top().second.second;
            ans=std::max(ans,first);
            pq.push({first+round*base,{base,round+1}});
            pq.pop();
        }
        return ans;
    }
};