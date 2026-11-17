// Problem 336: Palindrome Pairs
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/palindrome-pairs/

class Solution {
public:
    bool ispalindrome(const string& s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int>umap;
        vector<vector<int>>ans;
        for(int i=0;i<words.size();++i){
            string t=words[i];
            std::reverse(t.begin(),t.end());
            umap[t]=i;
        }
        for(int i=0;i<words.size();++i){
            if(umap.find(words[i])!=umap.end()&&umap[words[i]]!=i){
                ans.push_back({i,umap[words[i]]});
            }
            if(words[i]!=""&&ispalindrome(words[i],0,words[i].size()-1)&&umap.find("")!=umap.end()){
                ans.push_back({i,umap[""]});
                ans.push_back({umap[""],i});
            }
            for(int j=1;j<words[i].size();++j){
                string left=words[i].substr(0,j),right=words[i].substr(j);
                if(ispalindrome(words[i],0,j-1)&&umap.find(right)!=umap.end()){
                    ans.push_back({umap[right],i});
                }
                if(ispalindrome(words[i],j,words[i].size()-1)&&umap.find(left)!=umap.end()){
                    ans.push_back({i,umap[left]});
                }
            }
        }
        return ans;
    }
};