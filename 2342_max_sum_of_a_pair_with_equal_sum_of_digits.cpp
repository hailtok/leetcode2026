// Problem 2342: Max Sum of a Pair With Equal Sum of Digits
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>umap;
        unordered_map<int,int>check;
        for(int i=nums.size()-1;i>=0;--i){
            int sum=0,temp=nums[i];
            while(temp>0){
                sum+=temp%10;
                temp/=10;
            }
            check[sum]++;
            if(check[sum]<=2){
                umap[sum]+=nums[i];
            }
        }
        int answer=-1;
        auto it=umap.begin();
        for(auto j=check.begin();it!=umap.end();++it,++j){
            if(j->second!=1){
                answer=std::max(it->second,answer);
            }
        }
        return answer;
    }
};