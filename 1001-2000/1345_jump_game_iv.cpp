// Problem 1345: Jump Game IV
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/jump-game-iv/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>umap;
        for(int i=0;i<arr.size();++i){
            umap[arr[i]].push_back(i);
        }
        queue<int>que;
        vector<int>step(arr.size(),-1);
        step[arr.size()-1]=0;
        que.push(arr.size()-1);
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            if(cur==0){
                return step[0];
            }
            for(int i=0;i<umap[arr[cur]].size();++i){
                if(step[umap[arr[cur]][i]]==-1){
                    que.push(umap[arr[cur]][i]);
                    step[umap[arr[cur]][i]]=step[cur]+1;
                }
            }
            umap[arr[cur]].clear();
            if(cur+1<arr.size()&&step[cur+1]==-1){
                que.push(cur+1);
                step[cur+1]=step[cur]+1;
            }
            if(cur-1>=0&&step[cur-1]==-1){
                que.push(cur-1);
                step[cur-1]=step[cur]+1;
            }
        }
        return step[0];
    }
};