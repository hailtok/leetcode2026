// Problem 594: Longest Harmonious Subsequence
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();++i){
            ++mp[nums[i]];
        }
        if(mp.size()==1){
            return 0;
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            if(mp.find(it->first+1)!=mp.end()){
                ans=std::max(ans,it->second+mp[it->first+1]);
            }
        }
        return ans;
    }
};