// Problem 315: Count of Smaller Numbers After Self
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
private:
    vector<int>bits;
    int n;
    void update(int i,int val){
        while(i<=n){
            bits[i]+=val;
            i+=i&(-i);
        }
    }
    int query(int i){
        int sum=0;
        while(i>0){
            sum+=bits[i];
            i-=i&(-i);
        }
        return sum;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        vector<int>sorted_nums=nums;
        std::sort(sorted_nums.begin(),sorted_nums.end());
        sorted_nums.erase(unique(sorted_nums.begin(),sorted_nums.end()),sorted_nums.end());
        n=sorted_nums.size();
        bits.assign(n+1,0);
        vector<int>ans(nums.size());
        for(int i=nums.size()-1;i>=0;--i){
            int rank=lower_bound(sorted_nums.begin(),sorted_nums.end(),nums[i])-sorted_nums.begin()+1;
            ans[i]=query(rank-1);
            update(rank,1);
        }
        return ans;
    }
};