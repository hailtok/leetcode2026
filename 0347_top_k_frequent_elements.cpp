// Problem 347: Top K Frequent Elements
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>all;
        for(auto i:nums){
            all[i]++;
        }
        vector<int>answer;
        priority_queue <int,vector<int>,greater<int> >c;
        for (auto i:all) {
        c.push(i.second);
        }
        while(c.size()>k){
            c.pop();
        }
        for(auto i:all){
            if(i.second>=c.top()){
                answer.push_back(i.first);
            }
        }
        return answer;
    }
};