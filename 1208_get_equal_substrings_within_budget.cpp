// Problem 1208: Get Equal Substrings Within Budget
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        vector<int>cost(s.size());
        for(int i=0;i<s.size();++i){
            cost[i]=std::abs(s[i]-t[i]);
        }
        int left=0,right=0,cur=0;
        while(right<s.size()){
            cur+=cost[right];
            if(cur>maxCost){
                while(cur>maxCost&&left<=right){
                    cur-=cost[left];
                    ++left;
                }
            }
            ++right;
            ans=std::max(ans,right-left);
        }
        return ans;
    }
};