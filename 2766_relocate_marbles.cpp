// Problem 2766: Relocate Marbles
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/relocate-marbles/

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,bool>umap;
        for(int i=0;i<nums.size();++i){
            umap[nums[i]]=true;
        }
        for(int i=0;i<moveFrom.size();++i){
            umap[moveFrom[i]]=false;
            umap[moveTo[i]]=true;
        }
        vector<int>ans;
        for(auto it=umap.begin();it!=umap.end();++it){
            if(it->second){
                ans.push_back(it->first);
            }
            
        }
        std::sort(ans.begin(),ans.end());
        return ans;
    }
};