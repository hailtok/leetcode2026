// Problem 781: Rabbits in Forest
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rabbits-in-forest/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int rabbits=0;
        unordered_map<int,int>umap;
        for(int i=0;i<answers.size();++i){
            umap[answers[i]]++;
        }
        for(auto it=umap.begin();it!=umap.end();++it){
            int category=it->first+1;
            rabbits+=category*(it->second/category);
            if(it->second%category!=0){
                rabbits+=category;
            }
        }
        return rabbits;
    }
};