// Problem 493: Reverse Pairs
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    int total=0;
    vector<int> merge(vector<int>nums){
        if(nums.size()<=1){
            return nums;
        }
        auto mid=nums.begin()+nums.size()/2;
        vector<int>arr1(nums.begin(),mid);
        arr1=merge(arr1);
        vector<int>arr2(mid,nums.end());
        arr2=merge(arr2);
        vector<int>ans(nums.size());
        int i=0,j=0;
        for(int k=0;k<arr2.size();++k){
            long long target=2ll*arr2[k];
            total+=arr1.end()-upper_bound(arr1.begin(),arr1.end(),target);
        }
        while(i<arr1.size()&&j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                ans[i+j]=arr1[i];
                ++i;
            }
            else{
                ans[i+j]=arr2[j];
                ++j;
            }
        }
        while(i<arr1.size()){
            ans[i+j]=arr1[i];
            ++i;
        }
        while(j<arr2.size()){
            ans[i+j]=arr2[j];
            ++j;
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        merge(nums);
        return total;
    }
};