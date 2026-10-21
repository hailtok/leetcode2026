// Problem 1814: Count Nice Pairs in an Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-nice-pairs-in-an-array/

class Solution {
public:
    int rev(int num){
        int ans=0;
        while(num){
            ans*=10;
            ans+=num%10;
            num/=10;
        }
        return ans; 
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>umap;
        const int mod=1e9+7;
        for(int i=0;i<nums.size();++i){
            ++umap[nums[i]-rev(nums[i])];
        }
        long long ans=0;
        for(auto it=umap.begin();it!=umap.end();++it){
            ans+=(long long)it->second*(long long)(it->second-1)/2;
            ans%=mod;
        }
        return (int)ans;
    }
};