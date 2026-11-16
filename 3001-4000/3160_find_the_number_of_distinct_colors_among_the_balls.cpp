// Problem 3160: Find the Number of Distinct Colors Among the Balls
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans(queries.size(),0);
        unordered_map<int,int>ball,color;
        int distinct=0;
        for(int i=0;i<queries.size();++i){
            if(ball.count(queries[i][0])){
                --color[ball[queries[i][0]]];
                if(color[ball[queries[i][0]]]==0){
                    --distinct;
                }
            }
            ball[queries[i][0]]=queries[i][1];
            ++color[queries[i][1]];
            if(color[queries[i][1]]==1){
                ++distinct;
            }
            ans[i]=distinct;
        }
        return ans;
    }
};