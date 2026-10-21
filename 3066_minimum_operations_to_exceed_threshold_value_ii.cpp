// Problem 3066: Minimum Operations to Exceed Threshold Value II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=0;i<nums.size();++i){
            pq.push(nums[i]);
        }
        int count=0;
        while(pq.top()<k){
            long long temp=pq.top();
            pq.pop();
            pq.push(temp*2+pq.top());
            pq.pop();
            count++;
        }
        return count;
    }
};