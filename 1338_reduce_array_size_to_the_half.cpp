// Problem 1338: Reduce Array Size to The Half
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>mp;
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto [num, freq] : mp){
            pq.push(freq);
        }
        unsigned output=0,half=0;
        while(half<arr.size()/2){
            output++;
            half+=pq.top();
            pq.pop();
        }
        return output;
    }
};