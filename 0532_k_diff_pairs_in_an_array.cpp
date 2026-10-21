// Problem 532: K-diff Pairs in an Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();++i){
            ++umap[nums[i]];
        }
        int ans=0;
        for(auto it=umap.begin();it!=umap.end();++it){
            int count=umap.count(it->first+k);
            if(count){
                if(k==0){
                    ans+=it->second-1?1:0;
                }
                else{
                    ++ans;
                }
            }
        }
        return ans;
    }
};