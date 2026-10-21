// Problem 1711: Count Good Meals
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-good-meals/

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int>umap;
        int answer=0;
        for(int i=0;i<deliciousness.size();++i){
            int power=1;
            for(int j=0;j<22;++j){
                if(umap.count(power-deliciousness[i])){
                    answer+=umap[power-deliciousness[i]];
                    answer%=1000000007;
                }
                power<<=1;
            }
            umap[deliciousness[i]]++;
        }
        return answer;
    }
};