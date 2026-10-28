// Problem 915: Partition Array into Disjoint Intervals
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int>min_arr(nums.size());
        for(int i=nums.size()-1,min=nums[i];i>=0;--i){
            min_arr[i]=min;
            min=std::min(min,nums[i]);
        }
        int ans=1;
        for(int i=0,max=nums[0];i<nums.size();++i){
            max=std::max(max,nums[i]);
            cout<< max<<" "<< min_arr[i]<<endl;
            if(max<=min_arr[i]){
                ans=i;
                break;
            }
        }
        return ans+1;
    }
};