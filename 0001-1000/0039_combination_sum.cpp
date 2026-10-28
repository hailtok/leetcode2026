// Problem 39: Combination Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<int>numbers;
    vector<vector<int>>output;
    int goal;
    void recursion(vector<int>&arrays,int sum,int index){
        if(sum==goal){
            output.push_back(arrays);
            return;
        }
        if(numbers.size()==index){
            return;
        }
        while(index<numbers.size()&&sum+numbers[index]<=goal){
            arrays.push_back(numbers[index]);
            recursion(arrays,sum+numbers[index],index);
            index++;
            arrays.pop_back();
        }       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        goal=target;
        for(int i=0;i<candidates.size();i++){
            numbers.push_back(candidates[i]);
        }
        vector<int> a;
        recursion(a,0,0);
        return output;
    }
};