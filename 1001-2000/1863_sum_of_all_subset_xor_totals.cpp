// Problem 1863: Sum of All Subset XOR Totals
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int>temp;
        for(int i=0;i<nums.size();++i){
            int size=temp.size();
            for(int j=0;j<size;++j){
                temp.push_back(nums[i]^temp[j]);
            }
            temp.push_back(nums[i]);
        }
        int total=0;
        for(int i=0;i<temp.size();++i){
            total+=temp[i];
        }
        return total;
    }
};