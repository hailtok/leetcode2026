// Problem 1887: Reduction Operations to Make the Array Elements Equal
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int output=0,temp=0;
        map<int,int> order;
        for(int i=0;i<nums.size();i++){
            order[nums[i]]++;
        }
        for(map<int, int>::iterator it=order.end();it!=order.begin();it--){
            it->second+=temp;
            output+=it->second;
            temp=it->second;
        }
        return output;
    }
};