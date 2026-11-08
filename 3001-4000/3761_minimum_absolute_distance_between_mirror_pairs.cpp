// Problem 3761: Minimum Absolute Distance Between Mirror Pairs
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/

class Solution {
public:
    int reverse(int num){
        int ans=0;
        while(num>0){
            ans*=10;
            ans+=num%10;
            num/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>umap;
        int ans=1e9;
        for(int i=0;i<nums.size();++i){
            if(umap.find(nums[i])!=umap.end()){
                ans=std::min(ans,i-umap[nums[i]]);
            }
            umap[reverse(nums[i])]=i;
        }
        return ans==1e9?-1:ans;
    }
};