// Problem 525: Contiguous Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>umap{{0,-1}};
        int sum=0,ans=0;
        for(int i=0;i<nums.size();++i){
            nums[i]==0?--sum:++sum;
            if(umap.find(sum)!=umap.end()){
                ans=std::max(ans,i-umap[sum]);
            }
            else{
                umap[sum]=i;
            }
        }
        return ans;
    }
};