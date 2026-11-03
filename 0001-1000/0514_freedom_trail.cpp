// Problem 514: Freedom Trail
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/freedom-trail/

class Solution {
public:
    int memo[101][101];
    unordered_map<char,vector<int>>mp;
    int dfs(string& ring,int ring_idx,string& key,int key_idx){
        if(key_idx==key.size()){
            return 0;
        }
        if(memo[ring_idx][key_idx]!=-1){
            return memo[ring_idx][key_idx];
        }
        int min_step=INT_MAX;
        for(int i=0;i<mp[key[key_idx]].size();++i){
            int dist=std::abs(ring_idx-mp[key[key_idx]][i]);
            int rot_step=std::min(dist,(int)ring.size()-dist);
            int total=rot_step+1+dfs(ring,mp[key[key_idx]][i],key,key_idx+1);
            min_step=std::min(min_step,total);
        }
        memo[ring_idx][key_idx]=min_step;
        return min_step;
    }
    int findRotateSteps(string ring, string key) {
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<ring.size();++i){
            mp[ring[i]].push_back(i);
        }
        return dfs(ring,0,key,0);
    }
};