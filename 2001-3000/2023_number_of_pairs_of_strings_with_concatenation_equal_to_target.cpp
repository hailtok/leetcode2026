// Problem 2023: Number of Pairs of Strings With Concatenation Equal to Target
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution {
public:
    bool check(const string &s,const string &t,int start){
        for(int i=0;i<s.size();++i){
            if(s[i]!=t[start+i]){
                return false;
            }
        }
        return true;
    }
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,vector<int>>umap;
        for(int i=0;i<nums.size();++i){
            umap[nums[i]].push_back(i);
        }
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(check(nums[i],target,0)){
                string s=target.substr(nums[i].size());
                if(umap.count(s)){
                    if(nums[i]==s){
                        ans+=(umap[s].size()-1);
                    }
                    else{
                        ans+=umap[s].size();
                    }
                }
            }
        }
        return ans;
    }
};