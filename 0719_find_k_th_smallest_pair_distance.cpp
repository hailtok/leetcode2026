// Problem 719: Find K-th Smallest Pair Distance
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/find-k-th-smallest-pair-distance/

class Solution {
public:
    int countdistance(vector<int>&nums,int mid){
        int count=0,left=0;
        for(int right=0;right<nums.size();++right){
            while(nums[right]-nums[left]>mid){
                ++left;
            }
            count+=(right-left);
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        int low=0,high=nums.back()-nums.front();
        while(low<high){
            int mid=low+(high-low)/2,count=countdistance(nums,mid);
            if(count>=k){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};