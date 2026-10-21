// Problem 523: Continuous Subarray Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        umap[0]=-1;
        for(int i=0,count=0;i<nums.size();++i){
            count+=nums[i];
            count%=k;
            if(umap.find(count)==umap.end()){
                umap[count]=i;
            }
            else{
                if(i-umap[count]>=2){
                    return true;
                }
            }
        }
        return false;
    }
};