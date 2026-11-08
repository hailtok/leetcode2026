// Problem 3597: Partition String 
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/partition-string/

class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>ans;
        unordered_set<string>uset;
        string t="";
        for(int i=0;i<s.size();++i){
            t+=s[i];
            if(uset.find(t)==uset.end()){
                uset.insert(t);
                ans.push_back(t);
                t="";
            }
        }
        return ans;
    }
};