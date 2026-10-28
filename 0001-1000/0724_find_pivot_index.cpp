// Problem 724: Find Pivot Index
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix(nums.size()+1);
        int sum=nums[0];
        for(int i=0;i<nums.size();++i){
            sum=nums[i];
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<nums.size();++i){
            cout<<prefix[i]<<endl;
            cout<<prefix.back()-prefix[i]<<endl;
            if(prefix[i+1]==(prefix.back()-prefix[i])){
                return i;
            }
        }
        return -1;
    }
};