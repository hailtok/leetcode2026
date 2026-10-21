// Problem 219: Contains Duplicate II
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            if(umap.find(nums[i])==umap.end()){
                umap.insert({nums[i],i});
            }
            else{
                if(i-umap[nums[i]]<=k){
                    return true;
                }
                umap[nums[i]]=i;
            }
        }
        return false;
    }
};