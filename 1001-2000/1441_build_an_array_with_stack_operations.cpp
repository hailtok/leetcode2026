// Problem 1441: Build an Array With Stack Operations
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        for(int i=1,j=0;i<=n;++i){
            if(j==target.size()){
                break;
            }
            ans.push_back("Push");
            if(target[j]==i){
                ++j;
            }
            else{
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};