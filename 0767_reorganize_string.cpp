// Problem 767: Reorganize String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string s) {
        vector<int>alpha(26,0);
        for(int i=0;i<s.size();++i){
            ++alpha[s[i]-'a'];
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<alpha.size();++i){
            if(alpha[i]>0){
                pq.push({alpha[i],i+'a'});
            }
        }
        string ans="";
        while(pq.size()>1){
            auto a=pq.top();
            pq.pop();
            auto b=pq.top();
            pq.pop();
            ans+=a.second;
            ans+=b.second;
            --a.first;
            --b.first;
            if(a.first>0){
                pq.push(a);
            }
            if(b.first>0){
                pq.push(b);
            }
        }
        if(!pq.empty()){
            if(pq.top().first>1){
                return "";
            }
            ans+=pq.top().second;
        }
        return ans;
    }
};