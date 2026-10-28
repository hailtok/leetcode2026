// Problem 307: Range Sum Query - Mutable
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    vector<int>bits,num;
    NumArray(vector<int>& nums) {
        bits=vector<int>(nums.size()+1);
        num=nums;
        for(int i=0;i<nums.size();++i){
            bit_update(i,nums[i]);
        }
    }
    void bit_update(int x,int d){
        x++;
        for(int i=x;i<bits.size();i+=(i&-i)){
            bits[i]+=d;
        }
    }
    void update(int index, int val) {
        int new_val=val-num[index];
        num[index]=val;
        bit_update(index,new_val);
    }
    int getsum(int x){
        int sum=0;
        x++;
        for(int i=x;i>0;i-=(i&-i)){
            sum+=bits[i];
        }
        return sum;
    }
    int sumRange(int left, int right) {
        return getsum(right)-getsum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */