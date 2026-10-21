// Problem 423: Reconstruct Original Digits from English
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reconstruct-original-digits-from-english/

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char,int>umap;
        vector<int>nums(10);
        vector<vector<string>>pattern_nums={{"zero","two","four","six","eight"},{"one","three","five"},{"seven","nine"}};
        vector<vector<int>>hash={{0,2,4,6,8},{1,3,5},{7,9}};
        vector<vector<char>>keys={{'z','w','u','x','g'},{'o','h','f'},{'v','i'}};
        for(int i=0;i<s.size();++i){
            ++umap[s[i]];
        }
        for(int i=0;i<pattern_nums.size();++i){
            for(int j=0;j<pattern_nums[i].size();++j){
                int count=umap[keys[i][j]];
                nums[hash[i][j]]=count;
                for(int k=0;k<pattern_nums[i][j].size();++k){
                    umap[pattern_nums[i][j][k]]-=count;
                }
            }
        }
        string ans="";
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums[i];++j){
                ans+='0'+i;
            }
        }
        return ans;
    }
};