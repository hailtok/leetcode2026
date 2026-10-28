// Problem 455: Assign Cookies
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int answer=0;
        for(int i=0,j=0;i<g.size()&&j<s.size();){
            if(g[i]<=s[j]){
                i++;
                j++;
                answer++;
            }
            else{
                j++;
            }
        }
        return answer;
    }
};