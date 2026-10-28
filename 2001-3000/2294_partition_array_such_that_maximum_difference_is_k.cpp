// Problem 2294: Partition Array Such That Maximum Difference Is K
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxs=nums[0],mins=nums[0],answer=1;
        for(int i=0;i<nums.size();i++){
            maxs=max(maxs,nums[i]);
            mins=min(mins,nums[i]);
            if(abs(maxs-mins)>k){
                maxs=nums[i];
                mins=nums[i];
                answer++;
            }
        }
        return answer;
    }
};