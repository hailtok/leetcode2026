// Problem 274: H-Index
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        priority_queue<int> pq(begin(citations), end(citations));
        int output;
        for(output=0;!pq.empty()&&pq.top()>output;output++){
            pq.pop();
        }
        return output;
    }
};