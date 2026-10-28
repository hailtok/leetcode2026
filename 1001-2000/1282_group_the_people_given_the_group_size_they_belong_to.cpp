// Problem 1282: Group the People Given the Group Size They Belong To
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>output;
        vector<vector<int>>temp(groupSizes.size()+1);
        for(int i=0;i<groupSizes.size();i++){
            temp[groupSizes[i]].push_back(i);;
            if(temp[groupSizes[i]].size()==groupSizes[i]){
                output.push_back(temp[groupSizes[i]]);
                temp[groupSizes[i]].clear();
            }
        }
        return output;
    }
};