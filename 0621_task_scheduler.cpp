// Problem 621: Task Scheduler
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>count(26);
        for(int i=0;i<tasks.size();++i){
            ++count[tasks[i]-'A'];
        }
        for(int i=0;i<count.size();++i){
            if(count[i]!=0){
                pq.push(count[i]);
            }
        }
        int ans=0;
        while(!pq.empty()){
            int time=0;
            vector<int>temp;
            for(int i=0;i<n+1;++i){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                    ++time;
                }
            }
            for(int i=0;i<temp.size();++i){
                if(temp[i]>1){
                    pq.push(temp[i]-1);
                }
            }
            ans+=!pq.empty()?n+1:time;
        }
        return ans;
    }
};