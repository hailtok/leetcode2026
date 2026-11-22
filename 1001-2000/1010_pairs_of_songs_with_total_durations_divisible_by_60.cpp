// Problem 1010: Pairs of Songs With Total Durations Divisible by 60
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>umap;
        int ans=0;
        for(int i=0;i<time.size();++i){
            time[i]=time[i]%60;
            if(umap.find((60-time[i])%60)!=umap.end()){
                ans+=umap[(60-time[i])%60];
            }
            ++umap[time[i]];
        }
        return ans;
    }
};