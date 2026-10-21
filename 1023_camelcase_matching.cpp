// Problem 1023: Camelcase Matching
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/camelcase-matching/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans(queries.size(),0);
        for(int i=0;i<queries.size();++i){
            int j=0,k=0;
            while(j<queries[i].size()&&k<pattern.size()){
                if(isupper(queries[i][j])&&queries[i][j]!=pattern[k]){
                    break;
                }
                if(queries[i][j]==pattern[k]){
                    ++k;
                    if(k==pattern.size()){
                        ++j;
                        break;
                    }
                }
                ++j;
            }
            while(j<queries[i].size()){
                cout<<queries[i][j]<<endl;
                if(isupper(queries[i][j])){
                    //cout<<i<<endl;
                    --k;
                    break;
                }
                ++j;
            }
            
            if(k==pattern.size()){
                ans[i]=true;
            }
        }
        return ans;
    }
};