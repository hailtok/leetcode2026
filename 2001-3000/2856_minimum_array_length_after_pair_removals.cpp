// Problem 2856: Minimum Array Length After Pair Removals
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-array-length-after-pair-removals/

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();++i){
            umap[nums[i]]++;
        }
        int maximum=0;
        for(auto it=umap.begin();it!=umap.end();++it){
            maximum=std::max(maximum,it->second);
        }
        if(maximum<=nums.size()/2){
            return nums.size()%2;
        }
        return maximum*2-nums.size();
    }
};