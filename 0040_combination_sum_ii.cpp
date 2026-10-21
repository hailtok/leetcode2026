// Problem 40: Combination Sum II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    map<int,int>mp;
    vector<vector<int>> output;
    int goal,limit;
    void recursion(vector<int>array,map<int,int>::iterator it,int value){
        if(value==goal){
            output.push_back(array);
            return;
        }
        if(it==mp.end()||goal-value<(*it).first){
            return;
        }
        map<int,int>::iterator next=it;
        next++;
        for(int i=0;i<=it->second;i++){
            recursion(array,next,value+it->first*i);
            array.push_back(it->first);   
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(int i=0;i<candidates.size();i++){
            mp[candidates[i]]++;
        }
        goal=target;
        vector<int>temp;
        recursion(temp,mp.begin(),0);
        return output;
    }
};