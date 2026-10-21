// Problem 2558: Take Gifts From the Richest Pile
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/take-gifts-from-the-richest-pile/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();++i){
            pq.push(gifts[i]);
        }
        for(int i=0;i<k;++i){
            int temp=sqrt(pq.top());
            pq.pop();
            pq.push(temp);
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};