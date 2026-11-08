// Problem 1224: Maximum Equal Frequency
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/maximum-equal-frequency/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,unordered_set<int>>umap;
        unordered_map<int,int>freq;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            if(freq[nums[i]] > 0) {
                int old_f = freq[nums[i]];
                umap[old_f].erase(nums[i]);
                if(umap[old_f].empty()) {
                    umap.erase(old_f);
                }
            }
            ++freq[nums[i]];
            umap[freq[nums[i]]].insert(nums[i]);
            if(umap.size()==1){
                auto it=umap.begin();
                if(it->first==1||it->second.size()==1) {
                    ans=i+1;
                }
            }
            else if(umap.size()==2){
                auto it1=umap.begin(),it2=next(it1);
                if((it1->first==1&&it1->second.size()==1)||(it2->first==1&&it2->second.size()==1)){
                    ans=i+1;
                }
                else if((it1->first+1==it2->first&&it2->second.size()==1)||(it2->first+1==it1->first&&it1->second.size()==1)){
                    ans=i+1;
                }
            }
        }
        return ans;
    }
};