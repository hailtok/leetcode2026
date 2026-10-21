// Problem 164: Maximum Gap
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int num_max=INT_MIN,num_min=INT_MAX;
        for(int i=0;i<nums.size();++i){
            num_max=max(num_max,nums[i]);
        }
        for(int i=0;i<nums.size();++i){
            num_min=min(num_min,nums[i]);
        }
        int bucketsize=(num_max-num_min)/(nums.size()-1);
        if(bucketsize==0){
            bucketsize++;
        }
        int bucketcount=(num_max-num_min)/bucketsize+1;
        vector<int>max_bucket(bucketcount,INT_MIN);
        vector<int>min_bucket(bucketcount,INT_MAX);
        for(int i=0;i<nums.size();++i){
            max_bucket[(nums[i]-num_min)/bucketsize]=max(max_bucket[(nums[i]-num_min)/bucketsize],nums[i]);
            min_bucket[(nums[i]-num_min)/bucketsize]=min(min_bucket[(nums[i]-num_min)/bucketsize],nums[i]);
        }
        int answer=0,last=max_bucket[0];
        for(int i=1;i<bucketcount;++i){
            if(min_bucket[i]!=INT_MAX){
                answer=max(answer,min_bucket[i]-last);
                last=max_bucket[i];
            }
        }
        return answer;
    }
};